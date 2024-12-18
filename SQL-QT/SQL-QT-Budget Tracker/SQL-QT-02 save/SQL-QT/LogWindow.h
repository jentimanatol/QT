#ifndef LOGWINDOW_H
#define LOGWINDOW_H

#include <QWidget>
class MenuWindow; // Forward declaration

namespace Ui {
class LogWindow;
}

class LogWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LogWindow(QWidget *parent = nullptr);
    ~LogWindow();

private slots:
    void onLoginButtonClicked();

private:
    Ui::LogWindow *ui;
    MenuWindow *menuWindow; // Pointer to MenuWindow class
};

#endif // LOGWINDOW_H
