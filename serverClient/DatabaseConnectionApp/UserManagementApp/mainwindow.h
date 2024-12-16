#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize the database connection
    db = QSqlDatabase::addDatabase("QSQLITE");  // Example for SQLite
    db.setDatabaseName("path_to_database.db");

    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", "Unable to open database.");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    db.close();  // Don't forget to close the database connection
}
