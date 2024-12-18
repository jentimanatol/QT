#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)   // Initialize ui here
{
    ui->setupUi(this);  // Set up the UI

    // Initialize the model object
    model = new QSqlTableModel(this);
    model->setEditStrategy(QSqlTableModel::OnFieldChange);

    // Set up the button's clicked signal
    connect(ui->loadDataButton, &QPushButton::clicked, this, &MainWindow::loadData);
}

MainWindow::~MainWindow()
{
    delete ui;  // Clean up the UI object
}

void MainWindow::loadData()
{


    if (query.next()) {
        qDebug() << "Table 'User' exists!";
    } else {
        qDebug() << "Table 'User' does not exist!";
        return;
    }

    // Now load data from the User table
    model->setTable("User");
    if (!model->select()) {
        qDebug() << "Error loading data: " << model->lastError().text();
    } else {
        qDebug() << "Data loaded successfully from User table.";
    }
}
