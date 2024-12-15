#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Add a MySQL database connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    // Set connection parameters
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("usermanagement");
    db.setUserName("root");
    db.setPassword("admin");

    // Open the database connection
    if (!db.open()) {
        qDebug() << "Database connection failed!";
        qDebug() << db.lastError().text();
        return -1; // Exit application if connection fails
    }

    qDebug() << "Database connection successful!";

    // Test a simple query
    QSqlQuery query;
    if (query.exec("SELECT * FROM user")) {
        while (query.next()) {
            QString username = query.value("username").toString(); // Replace 'username' with actual column name
            qDebug() << "Username:" << username;
        }
    } else {
        qDebug() << "Query failed:" << query.lastError().text();
    }

    return app.exec();
}
