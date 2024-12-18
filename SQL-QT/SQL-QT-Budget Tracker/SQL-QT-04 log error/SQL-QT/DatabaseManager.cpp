#include "DatabaseManager.h"
#include <QCryptographicHash>

DatabaseManager& DatabaseManager::instance() {
    static DatabaseManager instance;
    return instance;
}

DatabaseManager::DatabaseManager() {
    // Constructor can be empty, as we'll handle DB connection explicitly
}

bool DatabaseManager::connectToDatabase() {
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("UserManagement");
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

bool DatabaseManager::validateUser(const QString &email, const QString &password) {
    if (!db.isOpen()) {
        qDebug() << "Database is not connected!";
        return false;
    }

    QSqlQuery query;
    query.prepare("SELECT password_hash FROM users WHERE email = :email");
    query.bindValue(":email", email);

    if (!query.exec()) {
        qDebug() << "Query failed:" << query.lastError().text();
        return false;
    }

    if (query.next()) {
        QString storedHash = query.value(0).toString();
        QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);

        return storedHash == hash.toHex();
    }

    return false;  // Email not found
}
