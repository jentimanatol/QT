#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>

class DatabaseManager
{
public:
    DatabaseManager();
    bool insertUserLogin(const QString &username, const QString &password, int accessLevel, int userID);
};

#endif // DATABASEMANAGER_H
