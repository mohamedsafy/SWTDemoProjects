#include "LibraryDatabase.h"
#include <fstream>
#include <cstdio>

LibraryDatabase::LibraryDatabase(const std::string &path) : filePath(path) {}

bool LibraryDatabase::loadData() {
    std::ifstream in(filePath.c_str());
    if (!in.is_open()) {
        return false;
    }

    nlohmann::json j;
    try {
        in >> j;
        books = j.value("books", std::vector<Book>());
        members = j.value("members", std::vector<Member>());
        logs = j.value("logs", std::vector<Transaction>());
    } catch (...) {
        return false;
    }
    return true;
}

bool LibraryDatabase::saveData() {
    nlohmann::json j;
    j["books"] = books;
    j["members"] = members;
    j["logs"] = logs;

    std::string tempPath = filePath + ".tmp";
    {
        std::ofstream out(tempPath.c_str(), std::ios::trunc);
        if (!out.is_open()) {
            return false;
        }
        out << j.dump(2);
        if (!out.good()) {
            return false;
        }
    }

    std::remove(filePath.c_str());
    if (std::rename(tempPath.c_str(), filePath.c_str()) != 0) {
        return false;
    }
    return true;
}

std::vector<Book> LibraryDatabase::getAllBooks() const {
    return books;
}

bool LibraryDatabase::getBookByISBN(const std::string &isbn, Book &book) const {
    std::vector<Book>::const_iterator it;
    for (it = books.begin(); it != books.end(); ++it) {
        if (it->isbn == isbn) {
            book = *it;
            return true;
        }
    }
    return false;
}

bool LibraryDatabase::getMemberById(int memberId, Member &member) const {
    std::vector<Member>::const_iterator it;
    for (it = members.begin(); it != members.end(); ++it) {
        if (it->memberId == memberId) {
            member = *it;
            return true;
        }
    }
    return false;
}

bool LibraryDatabase::updateBook(const Book &book) {
    std::vector<Book>::iterator it;
    for (it = books.begin(); it != books.end(); ++it) {
        if (it->isbn == book.isbn) {
            *it = book;
            return true;
        }
    }
    return false;
}

bool LibraryDatabase::updateMember(const Member &member) {
    std::vector<Member>::iterator it;
    for (it = members.begin(); it != members.end(); ++it) {
        if (it->memberId == member.memberId) {
            *it = member;
            return true;
        }
    }
    return false;
}

bool LibraryDatabase::addTransaction(const Transaction &transaction) {
    logs.push_back(transaction);
    return true;
}
