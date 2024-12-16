#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QFile>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString dbPath = "C:/BHCC/qt/serverClient/DatabaseConnectionApp/testdb2/usermanagement.db";

    // Check if the database file exists
    QFile dbFile(dbPath);
    if (!dbFile.exists()) {
        qDebug() << "Database file does not exist at:" << dbPath;
        return -1;
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);

    if (!db.open()) {
        qDebug() << "Error: Unable to connect to database." << db.lastError().text();
        return -1;
    }

    qDebug() << "Database connected successfully";

    QSqlQuery query;
    if (query.exec("SELECT name FROM users WHERE id = 1;")) {

            QString name = query.value(0).toString();
            qDebug() << "User Name:" << name;



    db.close();
    return a.exec();
}
