#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile file("input.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        ui->textEdit->setPlainText(in.readAll());
        file.close();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_findButton_clicked()
{
    QString searchTerm = ui->lineEdit->text();
    QString content = ui->textEdit->toPlainText();

    if (content.contains(searchTerm, Qt::CaseInsensitive)) {
        QMessageBox::information(this, "Search Result", "Text found!");
    } else {
        QMessageBox::information(this, "Search Result", "Text not found.");
    }
}
