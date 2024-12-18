#include "LogWindow.h"
#include "ui_LogWindow.h"
#include "MenuWindow.h" // Include the MenuWindow header

LogWindow::LogWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogWindow),
    menuWindow(nullptr)
{
    ui->setupUi(this);

    // Connect the login button to the slot
    connect(ui->pushButtonLogin, &QPushButton::clicked, this, &LogWindow::onLoginButtonClicked);
}

LogWindow::~LogWindow()
{
    delete ui;
    if (menuWindow) {
        delete menuWindow;
    }
}

void LogWindow::onLoginButtonClicked() {
    if (!menuWindow) {
        menuWindow = new MenuWindow();
    }
    menuWindow->show();
    this->hide(); // Hide the LogWindow
}
