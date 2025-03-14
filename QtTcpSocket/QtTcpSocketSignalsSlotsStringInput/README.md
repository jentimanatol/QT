# QtTcpSocketSignalsSlotsStringInput 
 
## Overview 
The QtTcpSocketSignalsSlotsStringInput is a Qt console application that demonstrates the use of QTcpSocket with signals and slots for TCP communication. This project showcases how to establish a TCP connection, send an HTTP GET request, and read the response using Qt's powerful networking capabilities. The application is designed to take a string as an input parameter, allowing for flexible and dynamic host connections. 
 
## Project Structure 
\``` 
QtTcpSocketSignalsSlotsStringInput.pro 
main.cpp 
mytcpclient.cpp 
mytcpclient.h 
\``` 
 
## Classes and Files 
 
### MyTcpClient Class 
- **File Name:** `mytcpclient.h`, `mytcpclient.cpp` 
- **Description:** Represents a TCP client that uses signals and slots to handle TCP socket events. 
- **Methods:** 
  - `MyTcpClient(QObject *parent = nullptr)`: Constructor to initialize the TCP client. 
  - `void connected()`: Slot called when the socket is connected. 
  - `void disconnected()`: Slot called when the socket is disconnected. 
  - `void readyRead()`: Slot called when data is available to read. 
 
### Main File 
- **File Name:** `main.cpp` 
- **Description:** Entry point of the application. Initializes and starts the TCP client. 
 
## How to Run the Project 
1. **Clone the Repository:** 
  \```sh 
  git clone https://github.com/jentimanatol/QT/tree/main/QtTcpSocketSignalsSlotsStringInput 
  cd QtTcpSocketSignalsSlotsStringInput 
  \``` 
 
2. **Open the Project in Qt Creator:** 
  - Open `QtTcpSocketSignalsSlotsStringInput.pro` in Qt Creator. 
 
3. **Build and Run the Project:** 
  - Click on the "Run" button in Qt Creator to build and run the project. 
 
## Features 
- **TCP Connection:** Establishes a TCP connection to a specified host. 
- **HTTP GET Request:** Sends an HTTP GET request to the host. 
- **Data Reading:** Reads and displays the response from the host. 
- **Dynamic Host Connection:** Allows for flexible and dynamic host connections by taking a string as an input parameter. 
 
## Screenshots 
![Application Output HTML](./QtTcpSocketSignalsSlotsStringInput/AplicationOutputhtml.jpg) 
![Application Output](./QtTcpSocketSignalsSlotsStringInput/AplicationOutput.jpg) 
 
## Diagrams 
### Project Structure Diagram 
![Project Structure Diagram](./QtTcpSocketSignalsSlotsStringInput/Untitled%20Diagram.drawio.png) 
 
### UML Diagram 
![UML Diagram](./QtTcpSocketSignalsSlotsStringInput/UMLDiagram.txt) 
 
### Detailed Diagram 
![Detailed Diagram](./QtTcpSocketSignalsSlotsStringInput/Untitled%20Diagram.drawio) 
 
## License 
This project is licensed under the MIT License - see the LICENSE file for details. 
 
## Acknowledgements 
- Qt for providing the framework for GUI development. 
- The authors of the C++ libraries used in this project. 
 
## Contact 
