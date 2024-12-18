# SQL-QT Project

Welcome to the **SQL-QT** project, a robust Qt-based application that integrates MySQL database functionality with an intuitive graphical user interface (GUI). This project demonstrates advanced Qt development practices, MySQL Connector integration, and a modular design for database-driven desktop applications.

---

## **Project Overview**

The **SQL-QT** project consists of a user management system featuring:
- **User Authentication**: Login system with email and password verification.
- **Financial Management**: Tracks income, expenses, and calculates total balances.
- **Customizable UI**: Built using Qt Designer and coded for extensibility.
- **MySQL Integration**: Uses MySQL Connector/C++ for seamless database operations.

---

## **Features**

### User Authentication
- Secure login with database-stored credentials.
- Real-time validation of email and password.
- Login success transitions to the main application menu.

### Financial Management
- Record income and expense entries.
- View and calculate total balance.
- Modular windows for each financial operation.

### Modular Design
- Separation of concerns with `LogWindow`, `DatabaseManager`, and other classes.
- Easy scalability for adding new features.

### Database Integration
- MySQL stored procedures for backend logic.
- Prepared statements for secure queries.
- Robust error handling for database connectivity issues.

---

## **Environment and Dependencies**

### **Development Environment**
- **Qt Framework**: Version 6.8.1 (MinGW 64-bit).
- **MySQL Connector/C++**: Version 9.1.
- **Operating System**: Windows 10/11 64-bit.

### **Required Software**
- [Qt Creator](https://www.qt.io/product/qt-creator) (with MinGW toolchain).
- [MySQL Server](https://dev.mysql.com/downloads/mysql/).
- [MySQL Connector/C++](https://dev.mysql.com/downloads/connector/cpp/).

### **Libraries and Tools**
- **Qt Modules**: Core, GUI, Widgets, SQL, Network.
- **Compiler**: MinGW 64-bit.

---

## **Project Structure**

### **Source Files**
- **`DatabaseManager.cpp`**: Handles database connection and query execution.
- **`LogWindow.cpp`**: Implements user authentication logic.
- **`IncomeEntry.cpp`**: Allows users to record income entries.
- **`ExpenseEntry.cpp`**: Allows users to record expense entries.
- **`MenuWindow.cpp`**: Main application menu after login.
- **`TotalBalance.cpp`**: Displays total income, expenses, and balance.

### **Header Files**
- **`DatabaseManager.h`**: Singleton class for managing database interactions.
- **`LogWindow.h`**: Defines the `LogWindow` class for the login interface.
- **Other Headers**: Corresponding to their respective source files.

### **UI Files**
- **`LogWindow.ui`**: GUI for user login.
- **`IncomeEntry.ui`**: GUI for income entry.
- **`ExpenseEntry.ui`**: GUI for expense entry.
- **`MenuWindow.ui`**: Main application menu.
- **`TotalBalance.ui`**: GUI for displaying balance information.

---

## **Setup Instructions**

### **Step 1: Install Dependencies**
- Download and install Qt 6.8.1 or later.
- Install MySQL Server and configure a database named `usermanagement`.
- Install MySQL Connector/C++ and ensure library paths are accessible.

### **Step 2: Configure the Database**
1. Create the `usermanagement` database.
2. Execute the following SQL commands to create tables and procedures:
   ```sql
   CREATE TABLE users (
       userID INT AUTO_INCREMENT PRIMARY KEY,
       email VARCHAR(100) NOT NULL UNIQUE,
       password VARCHAR(255) NOT NULL
   );

   DELIMITER $$
   CREATE PROCEDURE `UserLoginProcedure`(
       IN p_email VARCHAR(100),
       IN p_password VARCHAR(255),
       OUT p_userID INT
   )
   BEGIN
       SET p_userID = 0;
       SELECT userID INTO p_userID
       FROM users
       WHERE email = p_email AND password = p_password
       LIMIT 1;
   END $$
   DELIMITER ;
   ```

### **Step 3: Configure the Project**
1. Clone the repository or download the project files.
2. Open `SQL-QT.pro` in Qt Creator.
3. Modify the `.pro` file if necessary to update paths for MySQL Connector:
   ```plaintext
   LIBS += -L"C:/Program Files/MySQL/MySQL Connector C++ 9.1/lib64/vs14" -lmysqlcppconn -lmysqlcppconnx
   INCLUDEPATH += "C:/Program Files/MySQL/MySQL Connector C++ 9.1/include"
   INCLUDEPATH += "C:/Program Files/MySQL/MySQL Connector C++ 9.1/include/jdbc"
   ```

### **Step 4: Build and Run**
1. Select the **Desktop Qt 6.8.1 MinGW 64-bit** kit.
2. Clean the project: `Build > Clean All`.
3. Run qmake: `Build > Run qmake`.
4. Rebuild the project: `Build > Rebuild All`.
5. Run the application.

---

## **How to Use**

1. Launch the application.
2. On the login screen:
   - Enter your email and password.
   - Click **Login**.
   - If successful, the main menu appears.

3. From the main menu:
   - Navigate to **Income Entry** to add income records.
   - Navigate to **Expense Entry** to add expense records.
   - View your **Total Balance** for a summary.

---

## **Code Details**

### **Key Classes**
- **`DatabaseManager`**:
  - Singleton class for database interactions.
  - Methods: `connectToDatabase`, `loginUser`.

- **`LogWindow`**:
  - Implements login functionality.
  - Signals and slots connect GUI actions to backend logic.

### **Login Logic**
The `LogWindow` class connects to `DatabaseManager` to authenticate users via the stored procedure `UserLoginProcedure`.

### **Database Operations**
- Uses prepared statements for secure query execution.
- Implements robust error handling for database operations.

---

## **Known Issues and Future Enhancements**

### Known Issues
- Ensure MySQL Connector/C++ binaries match your Qt installation architecture.
- Stored procedure debugging may require enabling MySQL logs.

### Future Enhancements
- Add password hashing for improved security.
- Implement user roles and permissions.
- Extend financial features to include reporting and charts.

---

## **Contributing**
Contributions are welcome! Please fork the repository, create a branch, and submit a pull request.

---

## **Contact**
For questions or support, please contact:
- **Email**: support@sqlqtproject.com
- **GitHub**: [SQL-QT Repository](https://github.com/sql-qt)

---

Thank you for exploring the **SQL-QT** project!

