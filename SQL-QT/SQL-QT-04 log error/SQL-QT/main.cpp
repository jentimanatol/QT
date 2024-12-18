#include <QApplication>
#include "LogWindow.h"
#include "DatabaseManager.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Connect to the database
    if (!DatabaseManager::instance().connectToDatabase()) {
        return -1;  // If connection fails, terminate the app
    }

    // Show the login window
    LogWindow loginWindow;
    loginWindow.show();

    return app.exec();
}
