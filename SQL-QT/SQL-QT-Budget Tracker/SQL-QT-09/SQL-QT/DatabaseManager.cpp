#include "DatabaseManager.h"

DatabaseManager& DatabaseManager::instance() {
    static DatabaseManager instance;
    return instance;
}

bool DatabaseManager::connectToDatabase() {
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






#include "DatabaseManager.h"

bool DatabaseManager::loginUser(const QString &email, const QString &password, int &userID) {
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
        if (userID == 0) {
            qDebug() << "Login failed: Invalid credentials.";
            return false;
        }
        return true;
    } else {
        qDebug() << "No user found.";
        return false;
    }
}













/*

bool DatabaseManager::loginUser(const QString &email, const QString &password, int &userID) {
    QSqlQuery query;
    query.prepare("CALL UserLoginProcedure(:email, :password, @userID)");
    query.bindValue(":email", email);
    query.bindValue(":password", password);

    if (!query.exec()) {
        qDebug() << "Login failed:" << query.lastError().text();
        return false;
    }

    query.exec("SELECT @userID");
    if (query.next()) {
        userID = query.value(0).toInt();
        if (userID == 0) {
            qDebug() << "Login failed: Invalid credentials";
            return false;
        }
        return true;
    }
    return false;
}
*/
