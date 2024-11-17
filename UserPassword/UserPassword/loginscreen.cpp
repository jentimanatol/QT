#include "loginscreen.h"
#include "ui_loginscreen.h"
#include "user.h"
#include "superuser.h"
#include "encryption.h"
#include <QMessageBox>
#include <fstream>
#include <sstream>

LoginScreen::LoginScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginScreen)
{
    ui->setupUi(this);
    connect(ui->loginButton, &QPushButton::clicked, this, &LoginScreen::onLoginClicked);
    connect(ui->registerButton, &QPushButton::clicked, this, &LoginScreen::onRegisterClicked);
}

LoginScreen::~LoginScreen()
{
    delete ui;
}

void LoginScreen::onLoginClicked() {
    std::string username = ui->usernameEdit->text().toStdString();
    std::string password = ui->passwordEdit->text().toStdString();
    std::ifstream file("users.txt");
    std::string line;
    bool valid = false;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string storedUsername, storedPassword;
        std::getline(iss, storedUsername, ',');
        std::getline(iss, storedPassword, ',');
        if (decrypt(storedUsername) == username && decrypt(storedPassword) == password) {
            valid = true;
            break;
        }
    }
    if (valid) {
        QMessageBox::information(this, "Login", "Login successful!");
        // Move to the next screen
    } else {
        QMessageBox::warning(this, "Login", "Invalid username or password. Please try again.");
    }
}

void LoginScreen::onRegisterClicked() {
    std::string username = ui->usernameEdit->text().toStdString();
    std::string password = ui->passwordEdit->text().toStdString();
    std::ifstream file("users.txt");
    std::string line;
    bool exists = false;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string storedUsername;
        std::getline(iss, storedUsername, ',');
        if (decrypt(storedUsername) == username) {
            exists = true;
            break;
        }
    }
    if (exists) {
        QMessageBox::warning(this, "Register", "Username already exists. Please try again.");
    } else {
        std::ofstream file("users.txt", std::ios::app);
        file << encrypt(username) << "," << encrypt(password) << "\n";
        QMessageBox::information(this, "Register", "Registration successful!");
    }
}
