#include <sqlite3.h>
#include <iostream>
#include <string>
#include <climits>

int print_row(void *data, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i += 2) {
        std::cout << (argv[i] ? argv[i] : "NULL") << "   " << (argv[i + 1] ? argv[i + 1] : "NULL") << "\n";
    }
    return 0;
}

int main(int argc, char **argv) {
    sqlite3 *db;
    int rc, choice, id;
    std::string sql, name;
    char *err;

    // Connect to database "test.db"
    if (sqlite3_open("test.db", &db)) {
        std::cerr << "Cannot connect to db.";
        return 0;
    }

    // Create users table
    sql = "CREATE TABLE IF NOT EXISTS users(" \
           "id INTEGER PRIMARY KEY AUTOINCREMENT," \
           "name TEXT NOT NULL);";

    rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &err);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL Error: " << err;
    }

    // Show menu
    std::cout << "1. Show table \n" \
                 "2. Insert record \n" \
                 "3. Update record \n" \
                 "4. Delete record \n" \
                 "Enter your choice: ";

    // Read choice and clear '\n' from input stream
    std::cin >> choice;
    std::cin.ignore(INT_MAX, '\n');
    switch (choice) {
        case 1:
            sql = "SELECT * FROM users";
            std::cout << "id  Name\n";
            rc = sqlite3_exec(db, sql.c_str(), print_row, NULL, &err); // print_row is called for every row
            if (rc != SQLITE_OK) {
                std::cerr << "SQL Error: " << err;
            }
            break;
        case 2:
            std::cout << "Enter the name: ";
            std::getline(std::cin, name); // read into name
            sql = "INSERT INTO users(name) VALUES('" + name + "');";
            rc = sqlite3_exec(db, sql.c_str(), NULL, NULL, &err);
            if (rc != SQLITE_OK) {
                std::cerr << "SQL Error: " << err;
            }
            break;
        case 3:
            std::cout << "Enter id: ";
            std::cin >> id;
            std::cout << "Enter name: ";
            std::cin.ignore(INT_MAX, '\n');
            std::getline(std::cin, name);
            sql = "UPDATE users SET name = '" + name + "' WHERE id = " + std::to_string(id) +";";
            rc = sqlite3_exec(db, sql.c_str(), NULL, NULL, &err);
            if (rc != SQLITE_OK) {
                std::cerr << "SQL Error: " << err;
            }
            break;
        case 4:
            std::cout << "Enter id: ";
            std::cin >> id;
            sql = "DELETE FROM users WHERE id = " + std::to_string(id);
            rc = sqlite3_exec(db, sql.c_str(), NULL, NULL, &err);
            if (rc != SQLITE_OK) {
                std::cerr << "SQL Error: " << err;
            }
            break;
        default:
            std::cout << "Invalid Choice.\n";
    }

    // Close the connection
    sqlite3_close(db);
}
