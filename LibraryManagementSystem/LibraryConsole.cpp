#include "LibraryConsole.h"
#include <iostream>

LibraryConsole::LibraryConsole(const std::string &dbPath)
    : engine(dbPath), running(true) {}

void LibraryConsole::run() {
    std::cout << "=== Library Management System ===\n";
    while (true) {
        std::cout << "Enter Member ID (0 to exit): ";
        int memberId;
        std::cin >> memberId;
        if (!std::cin.good()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input.\n";
            continue;
        }
        if (memberId == 0) {
            return;
        }
        if (engine.login(memberId)) {
            std::cout << "Login successful.\n";
            break;
        }
        std::cout << "Invalid Member ID.\n";
    }

    while (running) {
        showMainMenu();
        handleUserInput();
    }
}

void LibraryConsole::showMainMenu() {
    std::cout << "\n1. Search/View Catalog\n";
    std::cout << "2. Borrow a Book\n";
    std::cout << "3. Return a Book\n";
    std::cout << "4. View My Borrowing History\n";
    std::cout << "5. Exit\n";
    std::cout << "Choose an option: ";
}

void LibraryConsole::handleUserInput() {
    int choice;
    std::cin >> choice;
    if (!std::cin.good()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid option.\n";
        return;
    }
    std::cin.ignore(10000, '\n');

    if (choice == 1) {
        std::vector<Book> available = engine.getAvailableBooks();
        std::cout << "\nAvailable books:\n";
        std::vector<Book>::iterator it;
        for (it = available.begin(); it != available.end(); ++it) {
            std::cout << "- " << it->title << " | " << it->author << " | " << it->isbn << " | Available\n";
        }

        std::cout << "Enter search query (title or ISBN), or press Enter to skip: ";
        std::string query;
        std::getline(std::cin, query);
        if (!query.empty()) {
            std::vector<Book> matched = engine.searchBooks(query);
            std::cout << "Search results:\n";
            if (matched.empty()) {
                std::cout << "No books found.\n";
            } else {
                for (it = matched.begin(); it != matched.end(); ++it) {
                    std::cout << "- " << it->title << " | " << it->author << " | " << it->isbn
                              << " | " << (it->isAvailable ? "Available" : "Borrowed") << "\n";
                }
            }
        }
    } else if (choice == 2) {
        std::cout << "Enter ISBN to borrow: ";
        std::string isbn;
        std::getline(std::cin, isbn);
        if (engine.borrowBook(isbn)) {
            std::cout << "Borrow successful.\n";
        } else {
            std::cout << "Book not available or invalid ISBN.\n";
        }
    } else if (choice == 3) {
        std::vector<std::string> borrowed = engine.getBorrowedBooks();
        if (borrowed.empty()) {
            std::cout << "You currently have no borrowed books.\n";
            return;
        }
        std::cout << "Your borrowed books:\n";
        std::vector<std::string>::iterator it2;
        for (it2 = borrowed.begin(); it2 != borrowed.end(); ++it2) {
            std::cout << "- " << *it2 << "\n";
        }
        std::cout << "Enter ISBN to return: ";
        std::string isbn;
        std::getline(std::cin, isbn);
        if (engine.returnBook(isbn)) {
            std::cout << "Return successful.\n";
        } else {
            std::cout << "Return failed.\n";
        }
    } else if (choice == 4) {
        std::vector<Transaction> history = engine.getBorrowingHistory();
        std::cout << "Borrowing history:\n";
        if (history.empty()) {
            std::cout << "No history found.\n";
        } else {
            std::vector<Transaction>::iterator it3;
            for (it3 = history.begin(); it3 != history.end(); ++it3) {
                std::cout << "- " << it3->date << " | " << it3->action << " | " << it3->isbn << "\n";
            }
        }
    } else if (choice == 5) {
        running = false;
        std::cout << "Goodbye.\n";
    } else {
        std::cout << "Invalid option.\n";
    }
}
