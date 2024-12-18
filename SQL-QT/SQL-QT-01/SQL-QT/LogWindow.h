#ifndef LOGWINDOW_H
#define LOGWINDOW_H

#include <QWidget>
#include <QMessageBox>
#include "DatabaseManager.h"

namespace Ui {
class LogWindow; // Forward declaration remains
}

class LogWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LogWindow(QWidget *parent = nullptr);
    ~LogWindow();

private slots:
    void attemptLogin();

private:
    Ui::LogWindow *ui; // This is fine if ui_LogWindow.h is included in the .cpp
    int userID;
};

#endif // LOGWINDOW_H
