#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connectToDatabase();

    // Connect the login button to the login procedure execution
    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::onLoginButtonClicked);
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

void MainWindow::onLoginButtonClicked() {
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    executeLoginProcedure(username, password);
}
