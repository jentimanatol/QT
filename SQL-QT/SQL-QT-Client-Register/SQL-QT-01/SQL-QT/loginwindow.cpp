#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QDebug>  // Added for terminal logging

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    // Log that the LoginWindow is initialized
    qDebug() << "LoginWindow initialized.";

    // Connect login and register buttons to their respective slots
    connect(ui->loginButton, &QPushButton::clicked, this, &LoginWindow::handleLogin);
    connect(ui->registerButton, &QPushButton::clicked, this, &LoginWindow::handleRegister);

    // Log the connection setup
    qDebug() << "Login and Register buttons connected.";

    // Call the database connection method
    connectToDatabase();
}

LoginWindow::~LoginWindow()
{
    // Log when the LoginWindow is being destroyed
    qDebug() << "LoginWindow destroyed.";

    delete ui;
}

// Database connection method
void LoginWindow::connectToDatabase()
{
    qDebug() << "Attempting to connect to the database...";

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("usermanagement");
    db.setUserName("root");
    db.setPassword("admin");
    db.setPort(3306);

    if (db.open()) {
        QMessageBox::information(this, "Database Connection", "Connected to the database.");
        qDebug() << "Database connected successfully.";
    } else {
        QMessageBox::critical(this, "Database Error", db.lastError().text());
        qDebug() << "Database connection failed. Error:" << db.lastError().text();
    }
}

// Handle login logic
void LoginWindow::handleLogin()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    qDebug() << "Login attempt with username:" << username;

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter both username and password.");
        qDebug() << "Input Error: Username or password is empty.";
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (query.exec()) {
        if (query.next()) {
            QMessageBox::information(this, "Login Success", "Login successful.");
            qDebug() << "Login successful for username:" << username;
            // Proceed to the main application window
        } else {
            QMessageBox::warning(this, "Login Failed", "Incorrect username or password.");
            qDebug() << "Login failed: Incorrect username or password for username:" << username;
        }
    } else {
        QMessageBox::critical(this, "Database Error", query.lastError().text());
        qDebug() << "Database error during login attempt:" << query.lastError().text();
    }
}

// Handle user registration
void LoginWindow::handleRegister()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    qDebug() << "Registration attempt with username:" << username;

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter both username and password.");
        qDebug() << "Input Error: Username or password is empty during registration.";
        return;
    }

    // Check if the username already exists
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username = :username");
    query.bindValue(":username", username);

    if (query.exec()) {
        if (query.next()) {
            QMessageBox::warning(this, "Registration Failed", "Username already exists.");
            qDebug() << "Registration failed: Username already exists for username:" << username;
        } else {
            // Insert new user into the database
            query.prepare("INSERT INTO users (username, password) VALUES (:username, :password)");
            query.bindValue(":username", username);
            query.bindValue(":password", password);

            if (query.exec()) {
                QMessageBox::information(this, "Registration Success", "User registered successfully.");
                qDebug() << "User successfully registered with username:" << username;
            } else {
                QMessageBox::critical(this, "Database Error", query.lastError().text());
                qDebug() << "Database error during registration:" << query.lastError().text();
            }
        }
    } else {
        QMessageBox::critical(this, "Database Error", query.lastError().text());
        qDebug() << "Database error while checking username during registration:" << query.lastError().text();
    }
}
