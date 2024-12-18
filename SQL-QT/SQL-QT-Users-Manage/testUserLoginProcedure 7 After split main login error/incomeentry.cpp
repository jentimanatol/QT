#include "incomeentry.h"
#include "ui_incomeentry.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

IncomeEntry::IncomeEntry(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IncomeEntry)
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
        populateSources();
    }
}

IncomeEntry::~IncomeEntry()
{
    delete ui;
}

void IncomeEntry::populateSources()
{
    QSqlQuery query("SELECT category FROM IncomeSource");
    while (query.next()) {
        QString category = query.value(0).toString();
        ui->sourceComboBox->addItem(category);
    }
}
