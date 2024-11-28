#pragma once
#include <iostream>
#include <sqlite3.h>

namespace SQL_Database {
    void createTable(sqlite3* db) {
        const char* sqlCreateTable =
            "CREATE TABLE IF NOT EXISTS Users ("
            "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
            "Name TEXT NOT NULL UNIQUE,"
            "Password TEXT NOT NULL);";

        char* errorMessage = NULL;  // �������� nullptr �� NULL
        if (sqlite3_exec(db, sqlCreateTable, nullptr, nullptr, &errorMessage) != SQLITE_OK) {
            std::cerr << "SQL error: " << errorMessage << std::endl;
            sqlite3_free(errorMessage);
        }
    }

    void addUser(sqlite3* db, const std::string& name, const std::string& password) {
        const char* sqlInsert = "INSERT INTO Users (Name, Password) VALUES (?, ?);";
        sqlite3_stmt* stmt;

        // ���������� SQL �������
        if (sqlite3_prepare_v2(db, sqlInsert, -1, &stmt, nullptr) != SQLITE_OK) {
            std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
            return;
        }

        // �������� ����������
        sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_STATIC);

        // ���������� �������
        if (sqlite3_step(stmt) != SQLITE_DONE) {
            std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
        }
        else {
            std::cout << "User added successfully!" << std::endl;
        }

        // ������������ ��������
        sqlite3_finalize(stmt);
    }

    bool loginUser(sqlite3* db, const std::string& name, const std::string& password) {
        const char* sqlSelect = "SELECT Password FROM Users WHERE Name = ?;";
        sqlite3_stmt* stmt;

        // ���������� SQL �������
        if (sqlite3_prepare_v2(db, sqlSelect, -1, &stmt, nullptr) != SQLITE_OK) {
            std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
            return false;
        }

        // �������� ���������
        sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);

        // ���������� �������
        if (sqlite3_step(stmt) == SQLITE_ROW) {
            const char* storedPassword = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
            if (storedPassword && password == storedPassword) {
                std::cout << "Login successful!" << std::endl;
                sqlite3_finalize(stmt);
                return true;
            }
            else {
                std::cerr << "Invalid password!" << std::endl;
            }
        }
        else {
            std::cerr << "User not found!" << std::endl;
        }

        sqlite3_finalize(stmt);
        return false;
    }

    void deleteUser(sqlite3* db, const std::string& name) {
        const char* sqlDelete = "DELETE FROM Users WHERE Name = ?;";
        sqlite3_stmt* stmt;

        // ���������� SQL �������
        if (sqlite3_prepare_v2(db, sqlDelete, -1, &stmt, nullptr) != SQLITE_OK) {
            std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
            return;
        }

        // �������� ���������
        sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);

        // ���������� �������
        if (sqlite3_step(stmt) != SQLITE_DONE) {
            std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
        }
        else {
            std::cout << "User deleted successfully!" << std::endl;
        }

        // ������������ ��������
        sqlite3_finalize(stmt);
    }

    void displayUsers(sqlite3* db) {
        const char* sqlSelect = "SELECT * FROM Users;";
        sqlite3_stmt* stmt;

        // ���������� SQL �������
        if (sqlite3_prepare_v2(db, sqlSelect, -1, &stmt, nullptr) != SQLITE_OK) {
            std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
            return;
        }

        std::cout << "Users in the database:\n";
        std::cout << "ID\tName\tPassword\n";
        std::cout << "----------------------------------\n";

        // ��������� ����������
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int id = sqlite3_column_int(stmt, 0);
            const char* name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            const char* password = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));

            std::cout << id << "\t" << (name ? name : "NULL") << "\t" << (password ? password : "NULL") << "\n";
        }

        // ������������ ��������
        sqlite3_finalize(stmt);
    }
} // namespace SQL_Database

int release() {
    sqlite3* db;
    const char* dbPath = "your_database.db";  // ������� ����� ���� � ����� ���� ������.

    // �������� ���� ������
    int rc = sqlite3_open(dbPath, &db);
    if (rc) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        return EXIT_FAILURE;
    }

    // �������� �������, ���� ��� �� ����������
    SQL_Database::createTable(db);

    int choice;
    do {
        std::cout << "Choose an option:\n";
        std::cout << "1. Register\n";
        std::cout << "2. Login\n";
        std::cout << "3. Delete User\n";
        std::cout << "4. Display Users\n";
        std::cout << "0. Exit\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: { // Register
            std::string name, password;
            std::cout << "Enter name: ";
            std::cin >> name;
            std::cout << "Enter password: ";
            std::cin >> password;
            SQL_Database::addUser(db, name, password);
            break;
        }
        case 2: { // Login
            std::string name, password;
            std::cout << "Enter name: ";
            std::cin >> name;
            std::cout << "Enter password: ";
            std::cin >> password;
            SQL_Database::loginUser(db, name, password);
            break;
        }
        case 3: { // Delete User
            std::string name;
            std::cout << "Enter name of user to delete: ";
            std::cin >> name;
            SQL_Database::deleteUser(db, name);
            break;
        }
        case 4: { // Display Users
            SQL_Database::displayUsers(db);
            break;
        }
        case 0: // Exit
            std::cout << "Exiting...\n";
            break;
        default:
            std::cerr << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

    // �������� ���� ������
    sqlite3_close(db);
    return 0;
}