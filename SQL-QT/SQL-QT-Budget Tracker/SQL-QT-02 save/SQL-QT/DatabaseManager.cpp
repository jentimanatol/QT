#include "DatabaseManager.h"

DatabaseManager& DatabaseManager::instance() {
    static DatabaseManager instance;
    return instance;
}

bool DatabaseManager::connectToDatabase() {
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost"); // Your database host
    db.setDatabaseName("your_database_name"); // Your database name
    db.setUserName("your_username"); // Your database username
    db.setPassword("your_password"); // Your database password
    db.setPort(3306); // Default MySQL port

    if (!db.open()) {
        qDebug() << "Database connection failed:" << db.lastError().text();
        return false;
    } else {
        qDebug() << "Database connected successfully!";
        return true;
    }
}
