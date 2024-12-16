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

    connect(ui->saveIncomeButton, &QPushButton::clicked, this, &IncomeEntry::saveIncome); // Connect save button to saveIncome slot
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

void IncomeEntry::saveIncome()
{
    QString source = ui->sourceComboBox->currentText();
    double amount = ui->amountLineEdit->text().toDouble();
    QString description = ui->descriptionLineEdit->text();

    QSqlQuery query;
    query.prepare("INSERT INTO Income (userID, source, amount, description, date) VALUES (:userID, :source, :amount, :description, :date)");
    query.bindValue(":userID", userID);
    query.bindValue(":source", source);
    query.bindValue(":amount", amount);
    query.bindValue(":description", description);
    query.bindValue(":date", ui->dateEdit->date());

    if (query.exec()) {
        qDebug() << "Income saved successfully!";
    } else {
        qDebug() << "Failed to save income:" << query.lastError().text();
    }
}
