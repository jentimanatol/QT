#include "main.h"

// Function to create the database connection
bool createDatabase() {
    // Create a connection to the SQLite database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("myDatabase.db");  // Name of the SQLite database file

    // Open the database
    if (!db.open()) {
        QMessageBox::critical(nullptr, "Database Error", db.lastError().text());
        return false;
    }

    return true;
}

// Function to create a table in the database
void createTable() {
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS person (id INTEGER PRIMARY KEY, name TEXT, age INTEGER)");
}

// Function to insert data into the table
void insertData() {
    QSqlQuery query;
    query.prepare("INSERT INTO person (name, age) VALUES (:name, :age)");
    query.bindValue(":name", "John Doe");
    query.bindValue(":age", 30);
    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Insert Error", query.lastError().text());
    }

    query.bindValue(":name", "Jane Doe");
    query.bindValue(":age", 25);
    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Insert Error", query.lastError().text());
    }
}

// Function to retrieve data from the table
void retrieveData() {
    QSqlQuery query("SELECT id, name, age FROM person");
    while (query.next()) {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        int age = query.value(2).toInt();

        qDebug() << "ID:" << id << ", Name:" << name << ", Age:" << age;
    }
}

// Function to close the database connection
void closeDatabase() {
    QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Create the database and check if it opens successfully
    if (!createDatabase()) {
        return -1;
    }

    // Create the table and insert data
    createTable();
    insertData();

    // Retrieve and display data from the table
    retrieveData();

    // Close the database connection
    closeDatabase();

    return a.exec();
}
