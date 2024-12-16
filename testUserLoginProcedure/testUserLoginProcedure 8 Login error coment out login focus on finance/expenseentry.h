#ifndef EXPENSEENTRY_H
#define EXPENSEENTRY_H

#include <QWidget>
#include <QSqlDatabase>

namespace Ui {
class ExpenseEntry;
}

class ExpenseEntry : public QWidget
{
    Q_OBJECT

public:
    explicit ExpenseEntry(QWidget *parent = nullptr);
    ~ExpenseEntry();

    void setUserID(int id) { userID = id; }

private:
    Ui::ExpenseEntry *ui;
    QSqlDatabase db;
    int userID;
    void populateCategories();
    void populateSubcategories(const QString &category);

private slots:
    void onCategoryChanged(const QString &category);
    void saveExpense();
};

#endif // EXPENSEENTRY_H
