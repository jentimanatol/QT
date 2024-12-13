# QtTcpSocket Signals and Slots Application

## Overview
This repository contains the solution for the **Topic 8 Reading Assignment** from the course *2024FA CSC-284-WB*. The project involves working with the Qt framework to create a TCP socket console application and progressively enhancing it to utilize signals and slots, demonstrating key Qt functionalities.

---

## Features

1. **Basic QtTcpSocket Application**:
   - Developed a console-based QtTcpSocket application.
   - Captured and showcased the output through a screenshot.

2. **Signals and Slots Integration**:
   - Modified the application to include Qt's **signals and slots** mechanism for better event handling.
   - Captured and showcased the output through a screenshot.

3. **Dynamic Connections**:
   - Enhanced the `doConnect` function to accept a string as an input parameter, allowing dynamic connections to hosts.
   - Tested the application with `bhcc.edu` and `www.bhcc.edu`.
   - Captured and showcased the output for each test through screenshots.

4. **Technical Questions**:
   - Provided detailed answers to the following questions:
     - What is the purpose of TCP?
     - How does TCP differ from FTP?
     - When might one use TCP?

---

## Project Structure

### Files
- **`main.cpp`**:
  - Contains the main logic for the QtTcpSocket application.
- **`screenshots/`**:
  - Directory containing screenshots of the application output.
- **`answers.pdf`**:
  - Document with answers to the assignment questions.

---

## Usage

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/QtTcpSocket.git
   cd QtTcpSocket
   ```

2. Build and run the project:
   - Open the project in Qt Creator.
   - Configure the Qt version and build environment.
   - Compile and run the application.

3. Test dynamic connections:
   - Modify the input string for `doConnect` in the application to test with different hosts (e.g., `bhcc.edu`, `www.bhcc.edu`).

---

## Screenshots
Screenshots of the application output are included in the `screenshots/` directory:
- Basic application output.
- Signals and slots integration.
- Tests with `bhcc.edu` and `www.bhcc.edu`.

---

## Technical Questions
Detailed answers to the assignment questions are provided in `answers.pdf`:
1. **Purpose of TCP**:
   - Explanation of TCP's role in ensuring reliable, ordered, and error-checked data delivery.
2. **Difference Between TCP and FTP**:
   - Comparison of TCP as a transport layer protocol versus FTP as an application layer protocol built on TCP.
3. **Use Cases for TCP**:
   - Examples of scenarios where TCP is preferred for its reliability and connection-oriented communication.

---

## Lessons Learned
This assignment demonstrated:
- The practical application of Qt's signals and slots mechanism.
- How to dynamically handle connections in a QtTcpSocket application.
- The importance of TCP in network communication and how it differs from other protocols like FTP.

---

## License
This project is licensed under the MIT License. See the `LICENSE` file for details.

---

## Acknowledgments
- Course resources and guidance provided by *2024FA CSC-284-WB*.
- Qt documentation and examples for TCP socket and signals/slots implementation.
