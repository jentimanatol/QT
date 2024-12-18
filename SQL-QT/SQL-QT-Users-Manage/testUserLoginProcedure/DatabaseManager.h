#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>

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
