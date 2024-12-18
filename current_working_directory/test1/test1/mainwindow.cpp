#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //make konection
   // conect (ui->btnAddTask, &QPushButton::clicked,this, &MainWindow::addTask );
   // connect(ui->btnAddTask, &QPushButton::clicked,  QApplication::instance() , &QApplication::quit );
      connect(ui->btnAddTask, &QPushButton::clicked,  this, &MainWindow::addTasks );
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::addTasks(){
    qDebug()<<"User click on the button ";

}
