#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    logWindow(nullptr)
{
    ui->setupUi(this);

    // Connect the START button to the slot
    connect(ui->pushButtonStart, &QPushButton::clicked, this, &Widget::onStartButtonClicked);
}

Widget::~Widget()
{
    delete ui;
    if (logWindow) {
        delete logWindow;
    }
}

void Widget::onStartButtonClicked()
{
    if (!logWindow) {
        logWindow = new LogWindow();
    }
    logWindow->show();
    this->hide(); // Hide the main Widget window
}
