#include "DatabaseManager.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
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
