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
        qDebug() << "Database connection failed:" << db.lastError().text();
        QMessageBox::critical(this, "Database Connection Failed", db.lastError().text());
    } else {
        qDebug() << "Database connected successfully!";
        QMessageBox::information(this, "Database Connection", "Database connected successfully!");
    }
}

void MainWindow::executeLoginProcedure(const QString &username, const QString &password) {
    QSqlQuery query;
    qDebug() << "Preparing query...";

    query.prepare("CALL UserLoginProcedure(:email, :password, @userID)");
    query.bindValue(":email", username);
    query.bindValue(":password", password);

    qDebug() << "Executing query...";
    if (!query.exec()) {
        qDebug() << "Procedure execution failed:" << query.lastError().text();
        QMessageBox::critical(this, "Procedure Execution Failed", query.lastError().text());
        return;
    }

    qDebug() << "Retrieving output...";
    if (!query.exec("SELECT @userID")) {
        qDebug() << "Failed to retrieve output variables:" << query.lastError().text();
        QMessageBox::critical(this, "Output Retrieval Failed", query.lastError().text());
        return;
    }

    if (query.next()) {
        int userID = query.value(0).toInt();
        qDebug() << "UserID:" << userID;
        QMessageBox::information(this, "Login Result", "User ID: " + QString::number(userID));
    } else {
        qDebug() << "Invalid username or password.";
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }
}

void MainWindow::onLoginButtonClicked() {
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    qDebug() << "Username:" << username << "Password:" << password;
    executeLoginProcedure(username, password);
}