#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onLoginButtonClicked();

private:
    Ui::MainWindow *ui;
    void connectToDatabase();
    void executeLoginProcedure(const QString &email, const QString &password);
};

#endif // MAINWINDOW_H
