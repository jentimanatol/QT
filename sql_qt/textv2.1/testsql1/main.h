#ifndef MAIN_H
#define MAIN_H

#include <QCoreApplication>
#include <QtSql>
#include <QMessageBox>  // Include here if using in multiple files

// Function declarations (prototypes)
bool createDatabase();
void createTable();
void insertData();
void retrieveData();
void closeDatabase();

#endif // MAIN_H
