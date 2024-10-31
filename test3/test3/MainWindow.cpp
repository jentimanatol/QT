#include "MainWindow.h"

#include "ui_mainwindow.h"
#include <QDebug>
//#include "ui_MainWindow.h"

#include "ui_mainwindow.h"
#include <QDebug>
#include <QMainWindow>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , model(new QStandardItemModel(this))
{
    ui->setupUi(this);

    // Set up the table model
    model->setHorizontalHeaderLabels({"Date", "Category", "Subcategory", "Amount"});
    ui->tableView->setModel(model);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_addExpenseButton_clicked() {
    // Get user input
    QDate date = QDate::fromString(ui->dateLineEdit->text(), "yyyy-MM-dd");
    QString category = ui->categoryLineEdit->text();
    QString subcategory = ui->subcategoryLineEdit->text();
    double amount = ui->amountLineEdit->text().toDouble();

    // Create an Expense object
    Expense expense(date, category, subcategory, amount);

    // Add the expense to the table model
    QList<QStandardItem *> items;
    items.append(new QStandardItem(expense.getDate().toString("yyyy-MM-dd")));
    items.append(new QStandardItem(expense.getCategory()));
    items.append(new QStandardItem(expense.getSubcategory()));
    items.append(new QStandardItem(QString::number(expense.getAmount())));
    model->appendRow(items);
}
