#include "expense.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Expense w;
    w.show();
    return a.exec();
}
