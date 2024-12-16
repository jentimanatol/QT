#include "expenseentry.h"
#include "ui_expenseentry.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

ExpenseEntry::ExpenseEntry(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExpenseEntry)
{
    ui->setupUi(this);

    // Connect to the database
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("usermanagement");
    db.setUserName("root");
    db.setPassword("admin");
    db.setPort(3306);

    if (!db.open()) {
        qDebug() << "Database Connection Failed:" << db.lastError().text();
    } else {
        qDebug() << "Database connected successfully!";
        populateCategories();
    }

    connect(ui->categoryComboBox, &QComboBox::currentTextChanged, this, &ExpenseEntry::onCategoryChanged);
}

ExpenseEntry::~ExpenseEntry()
{
    delete ui;
}

void ExpenseEntry::populateCategories()
{
    QSqlQuery query("SELECT DISTINCT category FROM ExpenseCategory");
    while (query.next()) {
        QString category = query.value(0).toString();
        ui->categoryComboBox->addItem(category);
    }
}

void ExpenseEntry::populateSubcategories(const QString &category)
{
    ui->subcategoryComboBox->clear();
    QSqlQuery query;
    query.prepare("SELECT subcategory FROM ExpenseCategory WHERE category = :category");
    query.bindValue(":category", category);
    if (query.exec()) {
        while (query.next()) {
            QString subcategory = query.value(0).toString();
            ui->subcategoryComboBox->addItem(subcategory);
        }
    } else {
        qDebug() << "Failed to retrieve subcategories:" << query.lastError().text();
    }
}

void ExpenseEntry::onCategoryChanged(const QString &category)
{
    populateSubcategories(category);
}
