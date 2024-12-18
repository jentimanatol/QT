#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Setting up the connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    // Set connection details
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("usermanagement");
    db.setUserName("root");
    db.setPassword("admin");

    // Set SSL options for secure connection
    db.setConnectOptions("MYSQL_OPT_SSL_KEY=C:/path/to/client-key.pem;"
                         "MYSQL_OPT_SSL_CERT=C:/path/to/client-cert.pem;"
                         "MYSQL_OPT_SSL_CA=C:/path/to/ca-cert.pem;");

    // Open the connection
    if (!db.open()) {
        qDebug() << "Database connection failed:" << db.lastError().text();
        return -1;
    }

    qDebug() << "Successfully connected to the database!";

    // Test the connection with a simple query
    QSqlQuery query("SELECT COUNT(*) FROM User");
    if (query.next()) {
        int userCount = query.value(0).toInt();
        qDebug() << "Number of users in the database:" << userCount;
    } else {
        qDebug() << "Query failed:" << query.lastError().text();
    }

    return a.exec();
}
