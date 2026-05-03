#ifndef LIBRARY_DATABASE_H
#define LIBRARY_DATABASE_H

#include <string>
#include <vector>
#include "Models.h"

class LibraryDatabase {
private:
    std::string filePath;
    std::vector<Book> books;
    std::vector<Member> members;
    std::vector<Transaction> logs;

public:
    explicit LibraryDatabase(const std::string &path);
    bool loadData();
    bool saveData();
    std::vector<Book> getAllBooks() const;
    bool getBookByISBN(const std::string &isbn, Book &book) const;
    bool getMemberById(int memberId, Member &member) const;
    bool updateBook(const Book &book);
    bool updateMember(const Member &member);
    bool addTransaction(const Transaction &transaction);
};

#endif
