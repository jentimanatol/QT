#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect buttons to their respective slots
    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::loginUser);
    connect(ui->registerButton, &QPushButton::clicked, this, &MainWindow::showRegisterForm);
    connect(ui->forgotPasswordButton, &QPushButton::clicked, this, &MainWindow::forgotPassword);
    connect(ui->registerUserButton, &QPushButton::clicked, this, &MainWindow::registerUser);
    connect(ui->backToLoginButton, &QPushButton::clicked, this, &MainWindow::showLoginForm);

    // Initialize the stacked widget to show login page first
    ui->stackedWidget->setCurrentWidget(ui->loginPage);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showRegisterForm()
{
    // Switch to the register page
    ui->stackedWidget->setCurrentWidget(ui->registerPage);
}

void MainWindow::showLoginForm()
{
    // Switch back to the login page
    ui->stackedWidget->setCurrentWidget(ui->loginPage);
}

void MainWindow::loginUser()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    // Example SQL query to authenticate user (replace with actual DB logic)
    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter both username and password.");
        return;
    }

    // Assuming a SQL database connection is established
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (!query.exec()) {
        QMessageBox::critical(this, "Login Error", "Database query failed: " + query.lastError().text());
        return;
    }

    if (query.next()) {
        // Successfully logged in
        QMessageBox::information(this, "Login Successful", "Welcome back, " + username + "!");
        // Optionally, switch to a main app screen here
    } else {
        // Login failed
        QMessageBox::warning(this, "Login Failed", "Incorrect username or password.");
    }
}

void MainWindow::registerUser()
{
    QString firstName = ui->firstNameLineEdit->text();
    QString lastName = ui->lastNameLineEdit->text();
    QString username = ui->registerUsernameLineEdit->text();
    QString password = ui->registerPasswordLineEdit->text();
    QString position = ui->positionComboBox->currentText();

    // Validate input fields
    if (firstName.isEmpty() || lastName.isEmpty() || username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill all fields.");
        return;
    }

    // SQL query to insert new user into the database
    QSqlQuery query;
    query.prepare("INSERT INTO users (first_name, last_name, username, password, position) "
                  "VALUES (:firstName, :lastName, :username, :password, :position)");
    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.bindValue(":position", position);

    if (!query.exec()) {
        QMessageBox::critical(this, "Registration Error", "Database error: " + query.lastError().text());
        return;
    }

    // Registration successful
    QMessageBox::information(this, "Registration Successful", "User registered successfully!");
    showLoginForm();  // Optionally, return to login page after successful registration
}

void MainWindow::forgotPassword()
{
    QMessageBox::information(this, "Forgot Password", "Password recovery is not implemented yet.");
}
