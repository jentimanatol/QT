
#include <QApplication>
#include <QDir>
#include "LogWindow.h"
#include "DatabaseManager.h"

int main(int argc, char *argv[])




{


    qDebug() << "Available SQL drivers:" << QSqlDatabase::drivers();




    QApplication app(argc, argv);

    QCoreApplication::addLibraryPath(QCoreApplication::applicationDirPath() + QDir::separator() + "sqldrivers");

    if (!DatabaseManager::instance().connectToDatabase()) {
        return -1;
    }

    LogWindow w;
    w.show();

    return app.exec();
}






/*

//#include <QWidget>
#include <QApplication>
#include "MenuWindow.h"
#include "DatabaseManager.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Attempt to connect to the database
    if (DatabaseManager::instance().connectToDatabase()) {
        qDebug() << "Database connection successful";
    } else {
        qDebug() << "Database connection failed";
    }

    MenuWindow w;
    w.show();

    return app.exec();
}


*/






/*#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
*/
