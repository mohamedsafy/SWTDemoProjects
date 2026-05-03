#ifndef MODELS_H
#define MODELS_H

#include <string>
#include <vector>
#include "json.hpp"

struct Transaction {
    std::string isbn;
    std::string action;
    std::string date;
};

struct Book {
    std::string isbn;
    std::string title;
    std::string author;
    bool isAvailable;

    void markBorrowed();
    void markReturned();
};

struct Member {
    int memberId;
    std::string name;
    std::vector<std::string> activeBorrowings;
    std::vector<Transaction> history;

    void addBorrowedBook(const std::string &isbn);
    void removeBorrowedBook(const std::string &isbn);
    void addTransaction(const Transaction &transaction);
};

void to_json(nlohmann::json &j, const Transaction &t);
void from_json(const nlohmann::json &j, Transaction &t);
void to_json(nlohmann::json &j, const Book &b);
void from_json(const nlohmann::json &j, Book &b);
void to_json(nlohmann::json &j, const Member &m);
void from_json(const nlohmann::json &j, Member &m);

#endif
