
# **Advanced Qt Project Collection**  
*Explore, Build, and Master the Art of C++ Development with Qt Framework*

Welcome to the **Advanced Qt Project Collection**, a treasure trove of innovative and practical projects built with the Qt framework. This repository is your gateway to mastering C++ programming, GUI development, and integrating powerful features like networking, databases, and more.  

Whether you're a student, an experienced developer, or someone passionate about problem-solving, these projects are designed to inspire, teach, and equip you with real-world development skills. Let's embark on this exciting journey together!

---

## 📚 **About This Collection**

This repository is a culmination of projects created during the **Advanced C++ / Object-Oriented Programming (OOP)** course at BHCC. Each project showcases a unique concept or application of the Qt framework, designed to reinforce modern C++ programming principles and Qt's versatility.  

From building dynamic GUIs to crafting robust backend systems, this collection demonstrates the synergy of creativity and technology.  

---

## ✨ **What You'll Find Here**

### **1. LoopBackExample**  
- A demonstration of loopback communication for testing network protocols.  
- **Key Features**: Learn about socket programming and internal communication without external dependencies.

### **2. QT-TasckList-App**  
- A to-do list application for managing tasks effectively.  
- **Key Features**: Add, edit, and remove tasks, with real-time tracking of pending and completed items.  

### **3. QT-TextFinder-App**  
- A text search tool that locates specific words or phrases in documents.  
- **Key Features**: File handling, regex-based searching, and error handling.

### **4. QtTcpSocket**  
- An example project using `QTcpSocket` for client-server communication.  
- **Key Features**: Learn how to send and receive data over TCP connections.

### **5. serverClient**  
- A robust implementation of server-client communication.  
- **Key Features**: Handle multiple clients, process requests, and manage data streams.

### **6. SQL-QT**  
- A database integration project connecting Qt with MySQL.  
- **Key Features**: CRUD operations, secure login functionality, and stored procedure integration.

### **7. UserPassword**  
- A password management system.  
- **Key Features**: Secure storage, password validation, and user-friendly UI.

### **8. current_working_directory**  
- A utility project for file and directory operations.  
- **Key Features**: File creation, directory navigation, and error handling.

---

## 🌍 **Setting Up Your Environment**

### **1. Install Qt Framework**  
1. Visit the [Qt Download Page](https://www.qt.io/download) and download the installer.
2. During installation, select:
   - **Qt Version**: 6.8.1 or higher.
   - **Compiler Kits**: Choose either:
     - MinGW 64-bit (13.1).
     - MSVC 2022 64-bit.
   - **Qt Modules**: Include SQL and Network modules.

3. After installation, verify the setup by launching **Qt Creator** and creating a sample project.

---

### **2. Install MySQL Server and Connector**  
1. Download and install [MySQL Community Server](https://dev.mysql.com/downloads/mysql/).  
2. Download the MySQL Connector driver compatible with your Qt installation:
   - For MinGW builds: Use `qsqlmysql.dll_Qt_SQL_driver_6.8.1_MinGW_13.1_64-bit.zip`.  
   - For MSVC builds: Use `qsqlmysql.dll_Qt_SQL_driver_6.8.1_MSVC2022_64-bit.zip`.  

3. Extract the `qsqlmysql.dll` file and place it in the `sqldrivers` directory of your Qt installation:  
   ```plaintext
   C:/Qt/6.8.1/mingw_64/plugins/sqldrivers/ (for MinGW)  
   C:/Qt/6.8.1/msvc_64/plugins/sqldrivers/ (for MSVC)  
   ```

4. Verify the SQL driver installation by running the following code:
   ```cpp
   #include <QDebug>
   #include <QSqlDatabase>
   int main() {
       qDebug() << "Available SQL drivers:" << QSqlDatabase::drivers();
       return 0;
   }
   ```
   Ensure `QMYSQL` is listed in the output.

---

### **3. Clone the Repository**  
Clone the repository to your local machine:
```bash
git clone https://github.com/jentimanatol/QT.git
cd QT
```

---

### **4. Open and Run a Project**  
1. Launch **Qt Creator**.  
2. Navigate to **File > Open File or Project** and select the `.pro` file for the desired project.  
3. Configure the build environment:
   - Choose a Kit compatible with your project (MinGW or MSVC).  
   - Run **qmake** if prompted.  
4. Build the project:
   - Select **Build > Build All**.  
5. Run the application:
   - Press `Ctrl + R` or select **Run > Start Debugging**.

---

## 🏗 **Repository Structure**

```plaintext
QT/
│
├── LoopBackExample/         # Loopback communication example
├── QT-TasckList-App/        # Task management application
├── QT-TextFinder-App/       # Text finder utility
├── QtTcpSocket/             # TCP socket communication example
├── serverClient/            # Server-client communication project
├── SQL-QT/                  # Database integration project
├── UserPassword/            # Password management application
├── current_working_directory/ # Utility project for file/directory operations

```

---

## 🚀 **Key Highlights**

- **Comprehensive Examples**: Covers a wide range of Qt use cases.
- **Scalable Codebases**: Modular design and maintainable architecture.
- **Hands-On Learning**: Practical implementation of theoretical concepts.

---

## 🛠 **Troubleshooting**

1. **Missing SQL Drivers**:
   - Ensure `qsqlmysql.dll` is in the correct `sqldrivers` folder.  
   - Verify that the Qt SQL module is installed.  

2. **Build Failures**:
   - Ensure the correct Kit is selected in Qt Creator.  
   - Clean and rebuild the project:  
     - Select **Build > Clean All**, then **Build > Rebuild All**.

3. **Database Errors**:
   - Confirm the database server is running.  
   - Verify connection credentials in the code.

---

## 📘 **Learning Outcomes**

By exploring these projects, you will:  
1. Build a solid foundation in C++ and Qt programming.  
2. Develop interactive GUI applications.  
3. Learn database integration and networking concepts.  
4. Understand advanced object-oriented design principles.  

---

## 🤝 **Contributing**

We welcome your contributions to enhance this repository!  
1. Fork the repository.  
2. Create a new branch for your changes.  
3. Submit a pull request with a clear description of your contributions.

---

## 📜 **License**

This repository is licensed under the [MIT License](LICENSE).  

---  

Unleash the potential of Qt and C++ with the **Advanced Qt Project Collection**. Start coding today! 🚀  

