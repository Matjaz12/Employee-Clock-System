#pragma once

#include "DBAdapter.h"
#include <iostream>
#include <WS2tcpip.h>
#pragma comment (lib,"ws2_32.lib")

class Server
{
public:
	Server(const unsigned int _portNumber, const char* _dataBasePath);
	~Server();
private:
	
	WSADATA wsData;
	WORD version;
	SOCKET listeningSocket;
	const unsigned int portNumber;
	fd_set socketSet;

	DBAdapter* dbAdapter = nullptr;

private:
	void intialize();
	void intializeSocketSet();
	void cleanup();
public:
	void run();
};

