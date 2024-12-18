#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Step 1: Create the database connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/BHCC/qt/serverClient/DatabaseConnectionApp/testdb2/usermanagement.db");  // Adjust the path

    if (!db.open()) {
        qDebug() << "Database connection failed: " << db.lastError().text();
        return -1;
    }

    qDebug() << "Database connected successfully";

    // Step 2: Create a query and fetch data
    QSqlQuery query;
    if (query.exec("SELECT id, username FROM users")) {
        while (query.next()) {
            int id = query.value(0).toInt();
            QString username = query.value(1).toString();
            qDebug() << "ID:" << id << "Username:" << username;
        }
    } else {
        qDebug() << "Query failed: " << query.lastError().text();
        return -1;
    }

    return a.exec();
}
