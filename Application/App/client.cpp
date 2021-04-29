#include "client.h"

Client::Client(const std::string _serverIPAddress, const unsigned int _serverPort)
    :
      serverIPAddress{_serverIPAddress},
      serverPort{_serverPort}
{
    // Try to Intialize clietn socket
    intialize();
}

Client::~Client()
{
    cleanup(); // Cleanup winsock
}


void Client::intialize()
{
    // Intialize Winsock
    version = MAKEWORD(2,2);
    int wsResult = WSAStartup(version, &wsData);
    if( wsResult != 0)
    {
        std::cerr<<"Can't intialize Winsock\n";
        throw std::exception();
    }
    // Connect to server
    //createSocket();

    // Hint Strucure
    hint.sin_family = AF_INET;
    hint.sin_port = htons(serverPort);
    inet_pton(AF_INET,serverIPAddress.c_str(), &hint.sin_addr);

}

void Client::createSocket()
{
    // Create a socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(clientSocket == INVALID_SOCKET)
    {
        std::cerr<<"Can't create a Socket\n";
        closesocket(clientSocket);
        WSACleanup();
        throw std::exception();
    }
}

void Client::connectToServer()
{
    // Connect to the server
    int connectionResult = connect(clientSocket, (sockaddr*)&hint, sizeof(hint));
    if(connectionResult == SOCKET_ERROR)
    {
        std::cerr<<"Can't connect to server\n";
        closesocket(clientSocket);
        WSACleanup();
        throw std::exception();
    }
}

std::vector<std::string> Client::sendMsg(const std::string message)
{
    /*
    Function creates a new Socket each time we want to send data to the server, since
    socket can't be used again after it is closed()

    Function tries to send a message to the server, it waits for server to return feeed back data,
    if server returns data, the function saves it in vector form and returns it to the caller
     */
    std::vector<std::string> receivedData;

    // 1. Create a new Socket and Connect to the Server
    createSocket();
    connectToServer();

    // 2. Send And Receive Data to/from Server

    if(message.size()>0)
    {
        char buffer[BUFFER_SIZE];
        int sendResult = send(clientSocket, message.c_str(), message.size() +1,0);
        if(sendResult != SOCKET_ERROR)
        {
            ZeroMemory(buffer,BUFFER_SIZE);
            int bytesReceived{};
            do
            {
                bytesReceived = recv(clientSocket, buffer, BUFFER_SIZE, 0);
                std::string receivedMsg = std::string(buffer,0,bytesReceived);
                if (receivedMsg == "DONE[]")
                {
                    // If server send back DONE[] Message, it is done sending data, and we can disconnect
                    break;
                }
                receivedData.push_back(receivedMsg);
                ZeroMemory(buffer,BUFFER_SIZE);


            }while(bytesReceived > 0);
        }
    }

    // 3. Close the client Socket Connection
    closesocket(clientSocket);
    return receivedData;
}

void Client::cleanup()
{
    WSACleanup();
}
