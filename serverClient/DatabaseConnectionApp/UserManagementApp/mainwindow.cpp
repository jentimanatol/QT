#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Database setup
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("users.db");

    if (!db.open()) {
        qDebug() << "Database connection failed: " << db.lastError().text();
    } else {
        qDebug() << "Database connected!";
    }

    // Connecting UI buttons to slots
    connect(ui->registerButton, &QPushButton::clicked, this, &MainWindow::showRegisterForm);
    connect(ui->backToLoginButton, &QPushButton::clicked, this, &MainWindow::showLoginForm);
    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::loginUser);
    connect(ui->registerUserButton, &QPushButton::clicked, this, &MainWindow::registerUser);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showRegisterForm()
{
    ui->stackedWidget->setCurrentIndex(1); // Show registration form
}

void MainWindow::showLoginForm()
{
    ui->stackedWidget->setCurrentIndex(0); // Show login form
}

void MainWindow::loginUser()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    QSqlQuery query;
    query.prepare("SELECT * FROM UserLogin WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (query.exec() && query.next()) {
        QMessageBox::information(this, "Login Success", "You have logged in successfully!");
    } else {
        QMessageBox::critical(this, "Login Failed", "Invalid username or password.");
    }
}

void MainWindow::registerUser()
{
    QString firstName = ui->firstNameLineEdit->text();
    QString lastName = ui->lastNameLineEdit->text();
    QString username = ui->registerUsernameLineEdit->text();
    QString password = ui->registerPasswordLineEdit->text();
    QString position = ui->positionComboBox->currentText();

    // Insert into User table
    QSqlQuery query;
    query.prepare("INSERT INTO User (firstName, lastName, position) VALUES (:firstName, :lastName, :position)");
    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);
    query.bindValue(":position", position);

    if (!query.exec()) {
        QMessageBox::critical(this, "Registration Failed", "Failed to insert user data.");
        return;
    }

    // Get the userID (autoincremented)
    int userID = query.lastInsertId().toInt();

    // Insert into UserLogin table
    query.prepare("INSERT INTO UserLogin (username, password, accessLevel, userID) VALUES (:username, :password, :accessLevel, :userID)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.bindValue(":accessLevel", position == "Admin" ? 1 : position == "Developer" ? 2 : 3);
    query.bindValue(":userID", userID);

    if (query.exec()) {
        QMessageBox::information(this, "Registration Success", "You have registered successfully!");
        ui->stackedWidget->setCurrentIndex(0); // Go back to login form
    } else {
        QMessageBox::critical(this, "Registration Failed", "Failed to insert login data.");
    }
}
