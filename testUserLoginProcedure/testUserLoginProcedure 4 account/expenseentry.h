#ifndef EXPENSEENTRY_H
#define EXPENSEENTRY_H

#include <QWidget>

namespace Ui {
class ExpenseEntry;
}

class ExpenseEntry : public QWidget
{
    Q_OBJECT

public:
    explicit ExpenseEntry(QWidget *parent = nullptr);
    ~ExpenseEntry();

private slots:
    void onSaveExpenseButtonClicked();

private:
    Ui::ExpenseEntry *ui;
};

#endif // EXPENSEENTRY_H
