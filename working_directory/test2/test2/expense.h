#ifndef EXPENSE_H
#define EXPENSE_H

#include <QString>
#include <QDate>

/**
 * @class Expense
 * @brief The Expense class represents an expense with a date, category, subcategory, and amount.
 */
class Expense {
public:
    /**
     * @brief Constructor for the Expense class.
     * @param date The date of the expense.
     * @param category The category of the expense.
     * @param subcategory The subcategory of the expense.
     * @param amount The amount of the expense.
     */
    Expense(QDate date, QString category, QString subcategory, double amount);

    /**
     * @brief Gets the date of the expense.
     * @return The date of the expense.
     */
    QDate getDate() const;

    /**
     * @brief Gets the category of the expense.
     * @return The category of the expense.
     */
    QString getCategory() const;

    /**
     * @brief Gets the subcategory of the expense.
     * @return The subcategory of the expense.
     */
    QString getSubcategory() const;

    /**
     * @brief Gets the amount of the expense.
     * @return The amount of the expense.
     */
    double getAmount() const;

    /**
     * @brief Sets the date of the expense.
     * @param date The new date of the expense.
     */
    void setDate(QDate date);

    /**
     * @brief Sets the category of the expense.
     * @param category The new category of the expense.
     */
    void setCategory(QString category);

    /**
     * @brief Sets the subcategory of the expense.
     * @param subcategory The new subcategory of the expense.
     */
    void setSubcategory(QString subcategory);

    /**
     * @brief Sets the amount of the expense.
     * @param amount The new amount of the expense.
     */
    void setAmount(double amount);

private:
    QDate date;
    QString category;
    QString subcategory;
    double amount;
};

#endif // EXPENSE_H
