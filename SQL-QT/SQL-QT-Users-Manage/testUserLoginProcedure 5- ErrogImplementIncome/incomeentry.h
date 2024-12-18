#ifndef INCOMEENTRY_H
#define INCOMEENTRY_H

#include <QWidget>
#include <QSqlDatabase>

namespace Ui {
class IncomeEntry;
}

class IncomeEntry : public QWidget
{
    Q_OBJECT

public:
    explicit IncomeEntry(QWidget *parent = nullptr);
    ~IncomeEntry();

private:
    Ui::IncomeEntry *ui;
    QSqlDatabase db;
    void populateSources();
};

#endif // INCOMEENTRY_H
