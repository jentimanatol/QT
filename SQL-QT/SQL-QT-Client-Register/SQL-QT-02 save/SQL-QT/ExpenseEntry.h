#ifndef EXPENSEENTRY_H
#define EXPENSEENTRY_H

#include <QWidget>
class MenuWindow; // Forward declaration

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
    void onReturnToMenuButtonClicked();

private:
    Ui::ExpenseEntry *ui;
    MenuWindow *menuWindow; // Pointer to MenuWindow class
};

#endif // EXPENSEENTRY_H
