#include "Server.h"
const char* databasePath = "enter_path_to_database";
const unsigned int serverPort = 8090;

int main()
{
	try
	{
		Server server(serverPort, databasePath);
		server.run();
	}
	catch (...)
	{
		std::cerr << "Exception thrown in Server";
	}
	return 0;
}