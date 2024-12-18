#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QPushButton>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void loadData();  // Declare the loadData function here

private:
    Ui::MainWindow *ui;
    QSqlTableModel *model;  // Declare model here
};

#endif // MAINWINDOW_H
