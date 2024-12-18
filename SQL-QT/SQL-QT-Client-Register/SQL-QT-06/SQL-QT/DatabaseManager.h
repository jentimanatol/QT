#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

class DatabaseManager {
public:
    static DatabaseManager& instance();
    bool connectToDatabase();

private:
    DatabaseManager() = default;
    QSqlDatabase db;
};

#endif // DATABASEMANAGER_H
