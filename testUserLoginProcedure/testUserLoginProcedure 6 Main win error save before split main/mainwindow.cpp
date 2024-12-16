

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "incomeentry.h"  // Include the header for IncomeEntry
#include "expenseentry.h" // Include the header for ExpenseEntry
#include "totalbalance.h" // Include the header for TotalBalance
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QVariant>
#include <QDebug>
#include <QInputDialog>

// MainWindow constructor
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

    // Connect buttons on the welcome page to their respective slots
    connect(ui->incomeEntryButton, &QPushButton::clicked, this, &MainWindow::onIncomeEntryButtonClicked);
    connect(ui->expenseEntryButton, &QPushButton::clicked, this, &MainWindow::onExpenseEntryButtonClicked);
    connect(ui->totalBalanceButton, &QPushButton::clicked, this, &MainWindow::onTotalBalanceButtonClicked);
}

// MainWindow destructor
MainWindow::~MainWindow()
{
    delete ui;
}

// Function to connect to the MySQL database
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

// Function to execute the login procedure
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
        ui->stackedWidget->setCurrentWidget(ui->welcomePage);
        ui->welcomeLabel->setText("Welcome, " + username + "!");

        // Set userID for IncomeEntry and ExpenseEntry windows
        IncomeEntry *incomeEntryWindow = new IncomeEntry();
        incomeEntryWindow->setUserID(userID);

        ExpenseEntry *expenseEntryWindow = new ExpenseEntry();
        expenseEntryWindow->setUserID(userID);

        TotalBalance *totalBalanceWindow = new TotalBalance();

        // Connect the buttons to their respective windows
        connect(ui->incomeEntryButton, &QPushButton::clicked, incomeEntryWindow, &QWidget::show);
        connect(ui->expenseEntryButton, &QPushButton::clicked, expenseEntryWindow, &QWidget::show);
        connect(ui->totalBalanceButton, &QPushButton::clicked, totalBalanceWindow, &QWidget::show);
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }
}















// Function to execute the registration procedure
void MainWindow::executeRegisterProcedure(const QString &firstName, const QString &lastName, const QString &username, const QString &password, const QString &position) {
    QSqlQuery query;

    query.prepare("CALL RegisterUser(:firstName, :lastName, :username, :password, :position, @userID)");
    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName, lastName);
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
        qDebug() << "New user ID:" << userID;

        QMessageBox::information(this, "Registration Successful", "User registered successfully!");
    } else {
        QMessageBox::warning(this, "Registration Failed", "Failed to register the user.");
    }
}

// Function to execute the forgot password procedure
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

    QMessageBox::information(this, "Password Reset", "Password reset successfully!");
}

// Slots implementation
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
    QString username = QInputDialog::getText(this, "Forgot Password", "Enter your username:");
    QString newPassword = QInputDialog::getText(this, "Forgot Password", "Enter your new password:", QLineEdit::Password);

    executeForgotPasswordProcedure(username, newPassword);
}

// Slots for budget management features
void MainWindow::onIncomeEntryButtonClicked() {
    IncomeEntry *incomeEntryWindow = new IncomeEntry();
    incomeEntryWindow->show();
}

void MainWindow::onExpenseEntryButtonClicked() {
    ExpenseEntry *expenseEntryWindow = new ExpenseEntry();
    expenseEntryWindow->show();
}

void MainWindow::onTotalBalanceButtonClicked() {
    TotalBalance *totalBalanceWindow = new TotalBalance();
    totalBalanceWindow->show();
}
