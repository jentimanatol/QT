#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect the button to the slot
    connect(ui->fetchDataButton, &QPushButton::clicked, this, &MainWindow::fetchData);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fetchData()
{
    // Set up the database connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/BHCC/qt/serverClient/DatabaseConnectionApp/testdb2/usermanagement.db");  // Corrected path

    // Open the database
    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", "Failed to open the database.");
        return;
    }

    // Query to fetch the ID from the customer table
    QSqlQuery query("SELECT id FROM customer");

    // Check if query was successful
    if (query.exec()) {
        QString result;
        while (query.next()) {
            int id = query.value(0).toInt();
            result += "Customer ID: " + QString::number(id) + "\n";
        }
        ui->outputLabel->setText(result);  // Display the result in the label
    } else {
        QMessageBox::critical(this, "Query Error", "Failed to execute the query.");
    }
}
