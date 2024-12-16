#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>  // For qDebug()
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , model(new QSqlTableModel(this))
{
    ui->setupUi(this);

    // Set up the database connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("usermanagement.db"); // Ensure the database is in the same directory as the executable.

    // Debug: print the database path
    qDebug() << "Database Path: " << db.databaseName();

    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", db.lastError().text());
        return;
    }

    qDebug() << "Database connected successfully!";

    // Connect the "Load Data" button to the loadData() slot
    connect(ui->loadButton, &QPushButton::clicked, this, &MainWindow::loadData);

    // Prepare the table view to display data
    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadData()
{
    // Debug: check the table existence
    QSqlQuery query;
    if (!query.exec("SELECT name FROM sqlite_master WHERE type='table' AND name='User';")) {
        qDebug() << "Error checking table existence: " << query.lastError().text();
        return;
    }

    if (query.next()) {
        qDebug() << "Table 'User' exists!";
    } else {
        qDebug() << "Table 'User' does not exist!";
        return;
    }

    // Now proceed to load data from the table
    qDebug() << "Loading data from User table...";

    model->setTable("User");
    if (!model->select()) {
        qDebug() << "Error loading data: " << model->lastError().text();
    } else {
        qDebug() << "Data loaded successfully from User table.";
    }
}
