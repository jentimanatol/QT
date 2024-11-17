#include <QCoreApplication>
#include "mytcpclient.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    MyTcpClient client;

    // Test with bhcc.edu
    client.doConnect("bhcc.edu");
    a.exec();

    // Test with www.bhcc.edu
    client.doConnect("www.bhcc.edu");
    return a.exec();
}
