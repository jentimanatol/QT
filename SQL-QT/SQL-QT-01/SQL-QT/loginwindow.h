#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>

namespace Ui {
class LoginWindow; // Forward declaration of the Ui::LoginWindow class, which is auto-generated from the .ui file.
}

// LoginWindow class inherits from QMainWindow to provide the basic window functionalities.
class LoginWindow : public QMainWindow
{
    Q_OBJECT // This macro is required for all Qt object classes, enabling the use of signals and slots.

public:
    // Constructor of the LoginWindow class, initializing the window and setting up the UI.
    explicit LoginWindow(QWidget *parent = nullptr);

    // Destructor of the LoginWindow class to clean up resources, including the UI object.
    ~LoginWindow();

private slots:
    // Slot to handle user login attempt. This will be triggered by the login button click.
    void handleLogin();

    // Slot to handle user registration attempt. This will be triggered by the register button click.
    void handleRegister();

private:
    Ui::LoginWindow *ui; // Pointer to the auto-generated UI class which handles all the widget elements.

    // Private method to handle the connection to the MySQL database.
    // This method is responsible for opening the database and handling any connection errors.
    void connectToDatabase();
};

#endif // LOGINWINDOW_H
