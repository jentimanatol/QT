#ifndef MAIN_H
#define MAIN_H

#include <QCoreApplication>
#include <QtSql>
#include <QMessageBox>
#include <QDebug>

bool createDatabase();
void createTable();
void insertData();
void retrieveData();
void closeDatabase();

#endif // MAIN_H
