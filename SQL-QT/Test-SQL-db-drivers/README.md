

# MySQL Database Connection & Qt GUI Application

## Introduction

Welcome to the **MySQL Database Connection & Qt GUI Application**! This guide explains how to set up and run a Qt-based C++ application that connects to a MySQL database and a batch script to clean up user configuration files.

The project consists of two major parts:

1. **Database Connection**: The C++ code that connects to a MySQL database (`usermanagement`) using Qt's SQL module.
2. **Qt GUI**: A basic Qt GUI application with a window layout set up via the `.ui` file.
3. **Batch Script**: A batch file (`delete_user_files.bat`) that deletes user-specific files (e.g., `.user` files).

This guide will provide detailed instructions on setting up and running each part, as well as explaining the functionality of each component.

---

## Project Overview

### 1. **Database Connection**

The C++ code provided demonstrates how to connect to a MySQL database using Qt's SQL module (`QSqlDatabase`). It first initializes the application and then attempts to connect to a database (`usermanagement`) running locally on the default port (3306).

Here’s the breakdown of the code:

```cpp
#include <QCoreApplication>
#include <QtSql>
#include <QDebug>

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    QCoreApplication::addLibraryPath("./sqldrivers");

    qDebug() << "Available drivers:" << QSqlDatabase::drivers();  // Prints available database drivers

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");  // Connect to MySQL database
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("usermanagement");
    db.setUserName("root");
    db.setPassword("admin");

    if (db.open()) {
        qDebug() << "Database connection successful!";  // Connection success message
    } else {
        qDebug() << "Database connection failed:" << db.lastError().text();  // Error message
    }

    return 0;
}
```

### Breakdown of Key Concepts

- **QSqlDatabase**: The class used to interact with SQL databases.
- **addDatabase("QMYSQL")**: Specifies the type of database (MySQL in this case).
- **setHostName, setPort, setDatabaseName, setUserName, setPassword**: These methods set the necessary connection details to connect to the database.
- **db.open()**: Attempts to open the database connection.
- **qDebug()**: Used to print messages to the console for debugging purposes.

#### Output:

- If the database connection is successful, it will print `"Database connection successful!"`.
- If it fails, the error message will provide details of the failure.

### 2. **Qt GUI Application (MainWindow)**

Next, the code provides a simple Qt GUI for managing the user interface (UI). The UI file (`mainwindow.ui`) defines the layout and elements in the window, such as the central widget, menu bar, and status bar.

#### `mainwindow.h` (Header File)

```cpp
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
```

#### `mainwindow.cpp` (Implementation File)

```cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
```

### Breakdown of Key Concepts

- **MainWindow Class**: This class inherits from `QMainWindow` and manages the main application window.
- **`setupUi`**: This function initializes the UI components defined in the `mainwindow.ui` file.
- **Destructor**: `delete ui;` ensures that the allocated memory for the UI components is freed when the window is destroyed.

### 3. **Qt Designer UI (XML File)**

This file, `mainwindow.ui`, was created using Qt Designer, which is a tool for designing GUIs for Qt applications.

```xml
<?xml version="1.0" encoding="UTF-8"?>
<ui version="4.0">
 <class>MainWindow</class>
 <widget class="QMainWindow" name="MainWindow">
  <property name="geometry">
   <rect>
    <x>0</x>
    <y>0</y>
    <width>800</width>
    <height>600</height>
   </rect>
  </property>
  <property name="windowTitle">
   <string>MainWindow</string>
  </property>
  <widget class="QWidget" name="centralwidget"/>
  <widget class="QMenuBar" name="menubar">
   <property name="geometry">
    <rect>
     <x>0</x>
     <y>0</y>
     <width>800</width>
     <height>22</height>
    </rect>
   </property>
  </widget>
  <widget class="QStatusBar" name="statusbar"/>
 </widget>
 <resources/>
 <connections/>
</ui>
```

### Breakdown of Key Concepts

- **QMainWindow**: The base class for a main window in Qt.
- **Central Widget**: The main widget where all other UI components are placed.
- **Menu Bar**: The bar at the top of the window that contains menus.
- **Status Bar**: A bar typically used to display information about the current status of the application.

### 4. **Batch Script (delete_user_files.bat)**

The batch script (`delete_user_files.bat`) is used to delete `.user` files from a specific directory. This script can be useful for cleaning up configuration files after testing or development.

```batch
@echo off
cd /d "%~dp0"
del /s *.user
```

#### Breakdown of the Batch Script

1. **@echo off**
   - **Purpose**: Hides the command execution to keep the output clean.
   
2. **cd /d "%~dp0"**
   - **Purpose**: Changes the working directory to the folder where the batch file is located, ensuring that the script operates on the right folder.

3. **del /s *.user**
   - **Purpose**: Deletes all `.user` files in the current directory and all subdirectories (`/s` flag).

---

## How to Run the Project

### 1. Setting Up the MySQL Database

- **Install MySQL**: Make sure you have MySQL installed on your system and that the MySQL server is running.
- **Create Database**: Create the `usermanagement` database and populate it with the necessary tables (e.g., a `users` table for storing user credentials).

### 2. Compiling and Running the Qt Application

- **Install Qt**: Make sure you have Qt and a compatible C++ compiler installed.
- **Open Qt Creator**: Open the project in Qt Creator.
- **Build and Run**: Build the project and run the application. The main window will open, and the application will attempt to connect to the MySQL database.

### 3. Running the Batch Script

- **Place the Batch Script**: Put the `delete_user_files.bat` in the directory where your `.user` files are located.
- **Run the Script**: Double-click the `.bat` file to delete all `.user` files in that directory.

---

## Conclusion

This project provides a complete demonstration of how to use Qt to create a GUI application that interacts with a MySQL database. It also includes a helpful batch script for cleaning up user settings. By following the steps in this README, you’ll be able to set up the project, run it, and customize it for your needs.

Let us know if you encounter any issues or have suggestions for improvement! Happy coding!