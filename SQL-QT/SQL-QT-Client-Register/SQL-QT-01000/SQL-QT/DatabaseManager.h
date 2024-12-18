#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class DatabaseManager {
public:
    static DatabaseManager& instance();
    bool connectToDatabase();
    bool loginUser(const QString &email, const QString &password, int &userID);

private:
    DatabaseManager() = default;
    QSqlDatabase db;
};

#endif // DATABASEMANAGER_H
