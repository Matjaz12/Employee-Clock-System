#include "Server.h"
const char* databasePath = "D://DesktopMT//FE//JobLoginProject//Database//employeeDatabase.db";
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