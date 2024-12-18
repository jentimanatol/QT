#include "DatabaseManager.h"
#include <QDebug>
#include <QCryptographicHash>

DatabaseManager::DatabaseManager()
{
    // Initialize the database connection here if needed
}

bool DatabaseManager::insertUserLogin(const QString &username, const QString &password, int accessLevel, int userID)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("path/to/your/database.db");

    if (!db.open()) {
        qDebug() << "Database connection failed:" << db.lastError().text();
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO UserLogin (username, password, accessLevel, userID) VALUES (:username, :password, :accessLevel, :userID)");
    query.bindValue(":username", username);
    query.bindValue(":password", password); // Consider hashing the password here
    query.bindValue(":accessLevel", accessLevel);
    query.bindValue(":userID", userID);

    if (query.exec()) {
        qDebug() << "User login added successfully!";
        return true;
    } else {
        qDebug() << "Failed to add user login:" << query.lastError().text();
        return false;
    }
}
