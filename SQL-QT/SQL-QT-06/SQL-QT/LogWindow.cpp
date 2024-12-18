#include "LogWindow.h"
#include <QVBoxLayout>
#include <QSqlError>
#include <QCryptographicHash>

LogWindow::LogWindow(QWidget *parent)
    : QWidget(parent),
    pushButtonLogin(new QPushButton("Login")),
    pushButtonRegister(new QPushButton("Register")),
    labelEmail(new QLabel("Email:")),
    labelPassword(new QLabel("Password:")),
    lineEditEmail(new QLineEdit),
    lineEditPassword(new QLineEdit)
{
    // Set up UI
    QVBoxLayout *layout = new QVBoxLayout;

    layout->addWidget(labelEmail);
    layout->addWidget(lineEditEmail);
    layout->addWidget(labelPassword);
    layout->addWidget(lineEditPassword);
    layout->addWidget(pushButtonLogin);
    layout->addWidget(pushButtonRegister);

    setLayout(layout);

    // Connect buttons to slots
    connect(pushButtonLogin, &QPushButton::clicked, this, &LogWindow::onLoginClicked);
    connect(pushButtonRegister, &QPushButton::clicked, this, &LogWindow::onRegisterClicked);

    // Open database
    if (!openDatabase()) {
        QMessageBox::critical(this, "Database Error", "Failed to open the database.");
    }
}

LogWindow::~LogWindow()
{
    if (db.isOpen()) {
        db.close();
    }
}

bool LogWindow::openDatabase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/server/SQL/gpt_db/usermanagement.db");

    if (!db.open()) {
        return false;
    }

    // Create table if it does not exist
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY AUTOINCREMENT, email TEXT NOT NULL UNIQUE, password TEXT NOT NULL)");

    return true;
}

bool LogWindow::registerUser(const QString &email, const QString &password)
{
    // Hash the password before storing it
    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);

    // Prepare the SQL query
    QSqlQuery query;
    query.prepare("INSERT INTO users (email, password) VALUES (:email, :password)");
    query.bindValue(":email", email);
    query.bindValue(":password", hashedPassword.toHex());

    if (!query.exec()) {
        QMessageBox::warning(this, "Registration Error", "Failed to register user: " + query.lastError().text());
        return false;
    }

    return true;
}

void LogWindow::onLoginClicked()
{
    QString email = lineEditEmail->text();
    QString password = lineEditPassword->text();

    // Check if the fields are empty (just a simple validation)
    if (email.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in both fields.");
    } else {
        // Handle login logic here
        QMessageBox::information(this, "Login", "Logging in with " + email);
    }
}

void LogWindow::onRegisterClicked()
{
    QString email = lineEditEmail->text();
    QString password = lineEditPassword->text();

    // Validate email and password
    if (email.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in both fields.");
        return;
    }

    // Register user in the database
    if (registerUser(email, password)) {
        QMessageBox::information(this, "Registration", "User successfully registered.");
    }
}
