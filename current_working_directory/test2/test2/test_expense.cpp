#include <QCoreApplication>
#include <QtTest>
#include "Expense.h"

class TestExpense : public QObject {
    Q_OBJECT

private slots:
    void testExpenseCreation();
    void testGettersAndSetters();
};

void TestExpense::testExpenseCreation() {
    QDate date(2023, 1, 2);
    Expense expense(date, "Automobile", "Gas", 23.43);

    QCOMPARE(expense.getDate(), date);
    QCOMPARE(expense.getCategory(), QString("Automobile"));
    QCOMPARE(expense.getSubcategory(), QString("Gas"));
    QCOMPARE(expense.getAmount(), 23.43);
}

void TestExpense::testGettersAndSetters() {
    Expense expense(QDate(2023, 1, 2), "Automobile", "Gas", 23.43);

    QDate newDate(2023, 2, 3);
    expense.setDate(newDate);
    QCOMPARE(expense.getDate(), newDate);

    expense.setCategory("Food");
    QCOMPARE(expense.getCategory(), QString("Food"));

    expense.setSubcategory("Groceries");
    QCOMPARE(expense.getSubcategory(), QString("Groceries"));

    expense.setAmount(50.00);
    QCOMPARE(expense.getAmount(), 50.00);
}

QTEST_MAIN(TestExpense)
#include "test_expense.moc"
