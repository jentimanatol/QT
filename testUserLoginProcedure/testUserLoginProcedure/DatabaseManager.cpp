

// DatabaseManager.h
#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>
#include <QSqlDatabase>

class DatabaseManager {
public:
    static DatabaseManager& instance();
    bool connectToDatabase();
    bool executeLoginProcedure(const QString &email, const QString &password, int &userID);

private:
    DatabaseManager() = default;
    QSqlDatabase db;
};

#endif // DATABASEMANAGER_H

// DatabaseManager.cpp
#include "DatabaseManager.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

DatabaseManager& DatabaseManager::instance() {
    static DatabaseManager instance;
    return instance;
}

bool DatabaseManager::connectToDatabase() {
    qDebug() << "Available drivers:" << QSqlDatabase::drivers(); // Verify available drivers

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("usermanagement");
    db.setUserName("root");
    db.setPassword("admin");
    db.setPort(3306);

    if (!db.open()) {
        qDebug() << "Database connection failed:" << db.lastError().text();
        return false;
    } else {
        qDebug() << "Database connected successfully!";
        return true;
    }
}

bool DatabaseManager::executeLoginProcedure(const QString &email, const QString &password, int &userID) {
    if (!db.isOpen()) {
        qDebug() << "Database is not open!";
        return false;
    }






    QSqlQuery query;
    query.prepare("CALL UserLoginProcedure(:email, :password, @userID)");
    query.bindValue(":email", email);
    query.bindValue(":password", password);

    if (!query.exec()) {
        qDebug() << "Procedure execution failed:" << query.lastError().text();
        return false;
    }

    if (!query.exec("SELECT @userID")) {
        qDebug() << "Failed to retrieve output variables:" << query.lastError().text();
        return false;
    }

    if (query.next()) {
        userID = query.value(0).toInt();
        return true;
    }

    return false;
}
