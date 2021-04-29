#include "mainwindow.h"
#include "client.h"
#include <QApplication>


const std::string _serverIPAddress = "enter_server_ip_address";
const unsigned int _serverPort = 8090;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Client tcpClient(_serverIPAddress,_serverPort);
    MainWindow w(&tcpClient);
    w.show();
    return a.exec();
}
