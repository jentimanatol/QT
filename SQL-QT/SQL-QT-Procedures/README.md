# SQL Procedures and Integrating Them into a Qt Environment

This tutorial will guide you through creating SQL procedures and incorporating them into a Qt application. We’ll cover the SQL database setup, creating stored procedures, and connecting these procedures in the Qt environment.

---

## 1. Setting Up the SQL Database

### Database Creation
Run the following SQL script in your database management system to create the `UserManagement` database and its associated tables:

```sql
CREATE DATABASE UserManagement;
USE UserManagement;

CREATE TABLE User (
    userID INT AUTO_INCREMENT PRIMARY KEY,
    firstname VARCHAR(50) NOT NULL,
    lastname VARCHAR(50) NOT NULL,
    position VARCHAR(50) NOT NULL
);

CREATE TABLE UserLogin (
    loginID INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(50) UNIQUE NOT NULL,
    password VARCHAR(255) NOT NULL,
    accessLevel INT NOT NULL,
    userID INT,
    FOREIGN KEY (userID) REFERENCES User(userID)
);

-- Insert sample data
INSERT INTO User (firstname, lastname, position) VALUES ('John', 'Doe', 'Developer');
INSERT INTO UserLogin (username, password, accessLevel, userID)
VALUES ('newUser', SHA2('password123', 256), 1, 1);
```

---

## 2. Creating SQL Stored Procedures

### Login Procedure
The `UserLoginProcedure` validates user credentials and retrieves the user's access level and ID.

```sql
DELIMITER //
CREATE PROCEDURE UserLoginProcedure (
    IN p_username VARCHAR(50),
    IN p_password VARCHAR(255),
    OUT p_accessLevel INT,
    OUT p_userID INT
)
BEGIN
    DECLARE temp_password VARCHAR(255);
    SET temp_password = SHA2(p_password, 256);

    SELECT accessLevel, userID
    INTO p_accessLevel, p_userID
    FROM UserLogin
    WHERE username = p_username AND password = temp_password
    LIMIT 1;

    IF p_userID IS NULL THEN
        SET p_accessLevel = NULL;
        SET p_userID = NULL;
    END IF;
END //
DELIMITER ;
```

### Registration Procedure
The `RegisterUser` procedure adds a new user and their login credentials.

```sql
DELIMITER //
CREATE PROCEDURE RegisterUser (
    IN p_firstName VARCHAR(50),
    IN p_lastName VARCHAR(50),
    IN p_username VARCHAR(50),
    IN p_password VARCHAR(255),
    IN p_position VARCHAR(50),
    OUT p_userID INT
)
BEGIN
    INSERT INTO User (firstname, lastname, position)
    VALUES (p_firstName, p_lastName, p_position);

    SET p_userID = LAST_INSERT_ID();

    INSERT INTO UserLogin (username, password, accessLevel, userID)
    VALUES (p_username, SHA2(p_password, 256), 1, p_userID);
END //
DELIMITER ;
```

### Forgot Password Procedure
The `ForgotPassword` procedure allows updating a user’s password.

```sql
DELIMITER //
CREATE PROCEDURE ForgotPassword (
    IN p_username VARCHAR(50),
    IN p_newPassword VARCHAR(255)
)
BEGIN
    UPDATE UserLogin
    SET password = SHA2(p_newPassword, 256)
    WHERE username = p_username;
END //
DELIMITER ;
```

---

## 3. Incorporating SQL Procedures into Qt

### Qt Database Connection
To connect to the database, modify the `connectToDatabase()` method in `mainwindow.cpp`:

```cpp
void MainWindow::connectToDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("usermanagement");
    db.setUserName("root");
    db.setPassword("admin");
    db.setPort(3306);

    if (!db.open()) {
        QMessageBox::critical(this, "Database Connection Failed", db.lastError().text());
    } else {
        QMessageBox::information(this, "Database Connection", "Database connected successfully!");
    }
}
```

### Login Procedure Integration
The `executeLoginProcedure` function calls the `UserLoginProcedure` stored procedure:

```cpp
void MainWindow::executeLoginProcedure(const QString &username, const QString &password) {
    QSqlQuery query;
    query.prepare("CALL UserLoginProcedure(:username, :password, @accessLevel, @userID)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (!query.exec()) {
        QMessageBox::critical(this, "Procedure Execution Failed", query.lastError().text());
        return;
    }

    if (query.exec("SELECT @accessLevel, @userID") && query.next()) {
        int accessLevel = query.value(0).toInt();
        int userID = query.value(1).toInt();
        QMessageBox::information(this, "Login Result", "Access Level: " + QString::number(accessLevel) + "\nUser ID: " + QString::number(userID));
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }
}
```

### Registration Procedure Integration
The `executeRegisterProcedure` function calls the `RegisterUser` procedure:

```cpp
void MainWindow::executeRegisterProcedure(const QString &firstName, const QString &lastName, const QString &username, const QString &password, const QString &position) {
    QSqlQuery query;
    query.prepare("CALL RegisterUser(:firstName, :lastName, :username, :password, :position, @userID)");
    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.bindValue(":position", position);

    if (query.exec() && query.exec("SELECT @userID") && query.next()) {
        int userID = query.value(0).toInt();
        QMessageBox::information(this, "Registration Successful", "User ID: " + QString::number(userID));
    } else {
        QMessageBox::critical(this, "Procedure Execution Failed", query.lastError().text());
    }
}
```

### Password Reset Integration
The `executeForgotPasswordProcedure` function calls the `ForgotPassword` procedure:

```cpp
void MainWindow::executeForgotPasswordProcedure(const QString &username, const QString &newPassword) {
    QSqlQuery query;
    query.prepare("CALL ForgotPassword(:username, :newPassword)");
    query.bindValue(":username", username);
    query.bindValue(":newPassword", newPassword);

    if (query.exec()) {
        QMessageBox::information(this, "Password Reset Successful", "Password has been reset successfully!");
    } else {
        QMessageBox::critical(this, "Procedure Execution Failed", query.lastError().text());
    }
}
```

---

## 4. Testing and Troubleshooting

### Testing SQL Procedures
Use the following commands to test the stored procedures directly in SQL:

```sql
CALL UserLoginProcedure('newUser', 'password123', @accessLevel, @userID);
SELECT @accessLevel, @userID;

CALL RegisterUser('Alice', 'Smith', 'alice123', 'password456', 'Admin', @userID);
SELECT @userID;

CALL ForgotPassword('alice123', 'newPassword789');
```

### Troubleshooting Connection Issues
- Verify that the MySQL Connector is installed: `mysql-connector-c++-9.1.0-winx64.msi` or `mysql-connector-c-6.1.11-winx64.msi`.
- Check SSL-related variables with:

```sql
SHOW VARIABLES LIKE 'have_openssl';
SHOW VARIABLES LIKE '%ssl%';
```

---

By following this guide, you’ll be able to manage SQL procedures efficiently and integrate them into your Qt application seamlessly. This template can be extended for future projects as needed.

