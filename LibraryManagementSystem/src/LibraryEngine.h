#ifndef LIBRARY_ENGINE_H
#define LIBRARY_ENGINE_H

#include <string>
#include <vector>
#include "LibraryDatabase.h"

class LibraryEngine {
private:
    LibraryDatabase db;
    Member currentMember;
    bool hasSession;

    std::string getCurrentDate() const;
    std::string toLower(const std::string &value) const;

public:
    explicit LibraryEngine(const std::string &dbPath);
    bool login(int memberId);
    std::vector<Book> searchBooks(const std::string &query);
    bool borrowBook(const std::string &isbn);
    bool returnBook(const std::string &isbn);
    std::vector<Transaction> getBorrowingHistory() const;
    std::vector<Book> getAvailableBooks();
    std::vector<std::string> getBorrowedBooks() const;
};

#endif
