#include "Server.h"

Server::Server(const unsigned int _portNumber, const char* _dataBasePath)
	:
	portNumber{_portNumber }
{
	// Try to intialize the TCP Server
	intialize();
	intializeSocketSet(); 

	// if server successfully intialized, crete a database adapter
	dbAdapter = new DBAdapter(_dataBasePath); 
}

Server::~Server()
{
	delete dbAdapter;
}

// Intialization

void Server::intialize()
{
	// Intialize winsock
	version = MAKEWORD(2, 2); // version 2.2
	int wsOk = WSAStartup(version, &wsData);
	if (wsOk != 0)
	{
		std::cerr << "Can't intialize winsock!\n";
		throw std::exception();
	}

	// Create listeing socket
	listeningSocket = socket(AF_INET, SOCK_STREAM, 0); //SOCK_STREAM -> Opens tcp socket 
	if (listeningSocket == INVALID_SOCKET)
	{
		std::cerr << "Can't create a socket!\n";
		throw std::exception();
	}
	
	// Bind IP Address and Port to listeing socket

	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(portNumber);
	hint.sin_addr.S_un.S_addr = INADDR_ANY;

	bind(listeningSocket, (sockaddr*)&hint, sizeof(hint));

	// Tell winsock the listeingSocket is for listening

	listen(listeningSocket, SOMAXCONN);
}

void Server::intializeSocketSet()
{
	FD_ZERO(&socketSet); // Clear the set
	FD_SET(listeningSocket, &socketSet); // Add listeing socket to the set
}

// Main Functionality

void Server::run()
{

	/*
	Funcion opens a new connection each time a new client connects to the server, it adds the connection 
	to the socket set and binds the client to a specific socket, this allows multiple clients to be connected at
	the same time.
	Function handles all connections in the same thread so while client A talks to the server, client B has to 
	wait until server is done talking to client A.
	*/

	std::cout << "Server is waiting for connections...\n";

	while (true)
	{
		fd_set copySocketSet = socketSet;

		int socketCount = select(0, &copySocketSet, nullptr, nullptr, nullptr);
		for (int i{ 0 }; i < socketCount; i++)
		{
			SOCKET socket = copySocketSet.fd_array[i];
			if (socket == listeningSocket)
			{
				SOCKET clientSocket = accept(listeningSocket, nullptr, nullptr); // Accept a new connection

				FD_SET(clientSocket, &socketSet); // Add new connection to the list of connected clients
			}
			else
			{
				// Setup buffer
				char buffer[4096];
				ZeroMemory(buffer, 4096);
		
				int bytesReceived = recv(socket, buffer, 4096, 0); // Receive message

				if (bytesReceived <= 0)
				{
					closesocket(socket); // Drop the client
					FD_CLR(socket, &socketSet);
				}
				else
				{
					/*
					Forward Raw Data received from a Client to the Database Adapter,
					in case client socket requested data from database we store the data in a vector
					and later send it back to client in pieces
					*/
					std::string rawMsg = std::string(buffer, 0, bytesReceived);
					std::vector<std::string> receivedDataFromDB = dbAdapter->processMsgFromServer(rawMsg);
					if (!receivedDataFromDB.empty())
					{
						// if we received some data from the database, we send it in pieces
						unsigned int dbDataLength = receivedDataFromDB.size();
						unsigned int counter = 0;
						while (counter < dbDataLength )
						{
							std::string data = receivedDataFromDB.back();
							receivedDataFromDB.pop_back();
							send(socket, data.c_str(), data.size() + 1, 0);
							counter++;
						}
					}
					std::string doneMsg = "DONE[]";
					send(socket, doneMsg.c_str(), doneMsg.size() + 1, 0); // after data was send we send a keyword to let client know, we are done and it can disconnect
				}
			}
		}// for()
	}// Loop()

	cleanup();
}

// Cleanup
void Server::cleanup()
{
	WSACleanup(); // Cleanup winsock
}