#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Database connection parameters
    QString dbPath = "C:/BHCC/qt/serverClient/DatabaseConnectionApp/testdb2/usermanagement.db";

    // Set up SQLite database connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);

    // Try to open the database
    if (!db.open()) {
        qDebug() << "Error: Unable to connect to database." << db.lastError().text();
        return -1;
    }

    // Print success message
    qDebug() << "Connected to database successfully";

    // Close the database connection
    db.close();

    return a.exec();
}
