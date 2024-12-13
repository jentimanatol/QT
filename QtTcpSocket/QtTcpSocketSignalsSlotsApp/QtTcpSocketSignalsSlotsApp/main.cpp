#include <QCoreApplication>
#include "mytcpclient.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    MyTcpClient client;
    client.doConnect("www.bhcc.edu");
    return a.exec();
}
