#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>  // For QMainWindow
#include <QPushButton>  // For QPushButton
#include <QLabel>       // For QLabel
#include <QSqlDatabase> // For database connectivity
#include <QSqlQuery>    // For executing SQL queries
#include <QMessageBox>  // For displaying messages

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
    void fetchData();  // Slot to fetch data from the database

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
