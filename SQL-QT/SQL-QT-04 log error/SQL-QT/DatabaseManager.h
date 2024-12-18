#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QString>
#include <QDebug>

class DatabaseManager {
public:
    static DatabaseManager& instance();
    bool connectToDatabase();
    bool validateUser(const QString &email, const QString &password);

private:
    DatabaseManager();
    QSqlDatabase db;
};

#endif // DATABASEMANAGER_H
