#include <QCoreApplication>
#include <QtSql>
#include <QDebug>

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    QCoreApplication::addLibraryPath("./sqldrivers");



    qDebug() << "Available drivers:" << QSqlDatabase::drivers();

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("usermanagement");
    db.setUserName("root");
    db.setPassword("admin");

    if (db.open()) {
        qDebug() << "Database connection successful!";
    } else {
        qDebug() << "Database connection failed:" << db.lastError().text();
    }

    return 0;
}
