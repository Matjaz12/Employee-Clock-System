#ifndef CLIENT_H
#define CLIENT_H

#include <WS2tcpip.h>
#pragma comment (lib,"ws2_32.lib")
#include <vector>
#include <iostream>

#define BUFFER_SIZE 4096

class Client
{
public:
    Client(const std::string _serverIPAddress, const unsigned int _serverPort);
    ~Client();
private:

    // Client Socket
    WSADATA wsData;
    WORD version;
    SOCKET clientSocket;
    sockaddr_in hint;

    // Server Info
    const std::string serverIPAddress;
    const unsigned int serverPort;

private:
    void intialize();
    void createSocket();
    void connectToServer();
    void cleanup();

public:
    std::vector<std::string> sendMsg(const std::string message);
};


#endif // CLIENT_H
