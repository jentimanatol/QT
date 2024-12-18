#include <QApplication>
#include "LogWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    LogWindow w;
    w.show();

    return app.exec();
}
