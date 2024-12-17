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

    void setUserID(int id) { userID = id; }

private:
    Ui::IncomeEntry *ui;
    QSqlDatabase db;
    int userID;
    void populateSources();

private slots:
    void saveIncome();
};

#endif // INCOMEENTRY_H
