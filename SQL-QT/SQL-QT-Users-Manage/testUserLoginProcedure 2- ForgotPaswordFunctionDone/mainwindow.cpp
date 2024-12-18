#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QVariant>
#include <QDebug>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connectToDatabase();

    // Connect the login button to the login procedure execution
    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::onLoginButtonClicked);

    // Connect the register button to the register procedure execution
    connect(ui->registerUserButton, &QPushButton::clicked, this, &MainWindow::onRegisterButtonClicked);

    // Connect the forgot password button to the forgot password procedure execution
    connect(ui->forgotPasswordButton, &QPushButton::clicked, this, &MainWindow::onForgotPasswordButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectToDatabase()
{
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

void MainWindow::executeLoginProcedure(const QString &username, const QString &password) {
    QSqlQuery query;

    query.prepare("CALL UserLoginProcedure(:username, :password, @accessLevel, @userID)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (!query.exec()) {
        qDebug() << "Procedure execution failed:" << query.lastError().text();
        QMessageBox::critical(this, "Procedure Execution Failed", query.lastError().text());
        return;
    }

    if (!query.exec("SELECT @accessLevel, @userID")) {
        qDebug() << "Failed to retrieve output variables:" << query.lastError().text();
        QMessageBox::critical(this, "Output Retrieval Failed", query.lastError().text());
        return;
    }

    if (query.next()) {
        int accessLevel = query.value(0).toInt();
        int userID = query.value(1).toInt();

        qDebug() << "Access Level:" << accessLevel << "UserID:" << userID;
        QMessageBox::information(this, "Login Result",
                                 "Access Level: " + QString::number(accessLevel) + "\n" +
                                     "User ID: " + QString::number(userID));
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }
}

void MainWindow::executeRegisterProcedure(const QString &firstName, const QString &lastName, const QString &username, const QString &password, const QString &position) {
    QSqlQuery query;

    query.prepare("CALL RegisterUser(:firstName, :lastName, :username, :password, :position, @userID)");
    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.bindValue(":position", position);

    if (!query.exec()) {
        qDebug() << "Procedure execution failed:" << query.lastError().text();
        QMessageBox::critical(this, "Procedure Execution Failed", query.lastError().text());
        return;
    }

    if (!query.exec("SELECT @userID")) {
        qDebug() << "Failed to retrieve output variable:" << query.lastError().text();
        QMessageBox::critical(this, "Output Retrieval Failed", query.lastError().text());
        return;
    }

    if (query.next()) {
        int userID = query.value(0).toInt();
        qDebug() << "New User ID:" << userID;
        QMessageBox::information(this, "Registration Successful", "User registered successfully!\nUser ID: " + QString::number(userID));
    }
}

void MainWindow::executeForgotPasswordProcedure(const QString &username, const QString &newPassword) {
    QSqlQuery query;

    query.prepare("CALL ForgotPassword(:username, :newPassword)");
    query.bindValue(":username", username);
    query.bindValue(":newPassword", newPassword);

    if (!query.exec()) {
        qDebug() << "Procedure execution failed:" << query.lastError().text();
        QMessageBox::critical(this, "Procedure Execution Failed", query.lastError().text());
        return;
    }

    QMessageBox::information(this, "Password Reset Successful", "Password has been reset successfully!");
}

void MainWindow::onLoginButtonClicked() {
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    executeLoginProcedure(username, password);
}

void MainWindow::onRegisterButtonClicked() {
    QString firstName = ui->firstNameLineEdit->text();
    QString lastName = ui->lastNameLineEdit->text();
    QString username = ui->registerUsernameLineEdit->text();
    QString password = ui->registerPasswordLineEdit->text();
    QString position = ui->positionComboBox->currentText();
    executeRegisterProcedure(firstName, lastName, username, password, position);
}

void MainWindow::onForgotPasswordButtonClicked() {
    QString username = ui->usernameLineEdit->text();
    QString newPassword = QInputDialog::getText(this, "Reset Password", "Enter new password:", QLineEdit::Password);
    if (!newPassword.isEmpty()) {
        executeForgotPasswordProcedure(username, newPassword);
    }
}
