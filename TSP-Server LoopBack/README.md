# Loopback Example Project

## Project Overview
The Loopback Example is a Qt-based project that demonstrates basic client-server communication using TCP sockets. It highlights how to set up a server, connect a client to the server, and perform bidirectional communication between them. The loopback mechanism echoes any received messages back to the sender, showcasing the interaction between the client and server within the same application.

### Key Features
- **TCP Server Initialization:** The application sets up a TCP server to listen for incoming connections on `localhost` and port `1234`.
- **Client-Server Connection:** A TCP client connects to the server on the same machine.
- **Message Echoing:** Messages received from the client are echoed back by the server.
- **GUI Controls:** The user interface provides buttons to start the server, connect the client, and log communication activities.

---

## File Breakdown
### `dialog.h`
Header file defining the `Dialog` class. This class manages the user interface and encapsulates server and client socket functionality.

#### Key Components:
- `QTcpServer *tcpServer;`: Pointer to the server instance.
- `QTcpSocket *tcpSocket;`: Pointer to the client socket.
- `QTcpSocket *clientSocket;`: Pointer to the client connection on the server side.

### `dialog.cpp`
Implementation of the `Dialog` class. It contains the logic for server setup, client connection, and message handling.

---

## Code Description
### Initialization
```cpp
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
    , tcpServer(new QTcpServer(this))
    , tcpSocket(new QTcpSocket(this))
    , clientSocket(nullptr)
{
    ui->setupUi(this);
    setWindowTitle("Loopback Example - Your Name");

    connect(ui->startServerButton, &QPushButton::clicked, this, &Dialog::startServer);
    connect(ui->connectButton, &QPushButton::clicked, this, &Dialog::connectToServer);
    connect(tcpServer, &QTcpServer::newConnection, this, &Dialog::acceptConnection);
}
```
This constructor initializes the server and client sockets, connects GUI buttons to their respective slots, and sets up the server to accept new connections.

### Starting the Server
```cpp
void Dialog::startServer()
{
    if (!tcpServer->listen(QHostAddress::LocalHost, 1234)) {
        ui->logTextEdit->append("Server could not start!");
    } else {
        ui->logTextEdit->append("Server started...");
    }
}
```
The `startServer` method configures the TCP server to listen for connections on `localhost` and port `1234`. Logs indicate the server's status.

### Connecting to the Server
```cpp
void Dialog::connectToServer()
{
    tcpSocket->connectToHost(QHostAddress::LocalHost, 1234);
    connect(tcpSocket, &QTcpSocket::readyRead, this, &Dialog::startRead);
    ui->logTextEdit->append("Connecting to server...");
}
```
The `connectToServer` method establishes a client connection to the server and connects the `readyRead` signal to handle incoming data.

### Accepting Client Connections
```cpp
void Dialog::acceptConnection()
{
    clientSocket = tcpServer->nextPendingConnection();
    connect(clientSocket, &QTcpSocket::readyRead, this, &Dialog::startRead);
    ui->logTextEdit->append("Client connected...");
}
```
The `acceptConnection` method is triggered when a new connection is established. It retrieves the client socket and connects its `readyRead` signal for data handling.

### Reading and Echoing Data
```cpp
void Dialog::startRead()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (socket) {
        QByteArray data = socket->readAll();
        ui->logTextEdit->append("Received: " + data);
        socket->write(data);
    }
}
```
The `startRead` method processes incoming data, displays it in the log, and echoes the message back to the sender.

---

## How to Use
1. **Setup:**
   - Build and run the project in Qt Creator.

2. **Start the Server:**
   - Click the "Start Server" button.
   - Observe the "Server started..." message in the log.

3. **Connect the Client:**
   - Click the "Connect to Server" button.
   - Observe the "Connecting to server..." message in the log.
   - Upon successful connection, the log will show "Client connected...".

4. **Send and Receive Messages:**
   - Use the integrated log or custom UI controls (not implemented here) to send messages.
   - Messages sent by the client are echoed back by the server and displayed in the log.

---

## Features and Functionality
- **Real-Time Communication:** This project illustrates real-time data exchange between a client and a server.
- **Easy to Extend:** Additional features, such as authentication or file transfer, can be integrated easily.
- **Educational Value:** Ideal for understanding the basics of network programming with Qt.

---

## Future Improvements
- **Error Handling:** Add more robust error management for socket operations.
- **GUI Enhancements:** Provide a dedicated input field for sending messages.
- **Multi-Client Support:** Extend server functionality to handle multiple clients simultaneously.

---

## References
- [Qt Documentation on QTcpServer](https://doc.qt.io/qt-5/qtcpserver.html)
- [Qt Documentation on QTcpSocket](https://doc.qt.io/qt-5/qtcpserver.html)

---

This project serves as a stepping stone for more advanced networking applications. Happy coding!




_Not protected by copyright, may be used for its intended purpose._  
_Author: Anatolie Jentimir._



