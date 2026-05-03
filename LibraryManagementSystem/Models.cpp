#include "Models.h"
#include <algorithm>

void Book::markBorrowed() {
    isAvailable = false;
}

void Book::markReturned() {
    isAvailable = true;
}

void Member::addBorrowedBook(const std::string &isbn) {
    if (std::find(activeBorrowings.begin(), activeBorrowings.end(), isbn) == activeBorrowings.end()) {
        activeBorrowings.push_back(isbn);
    }
}

void Member::removeBorrowedBook(const std::string &isbn) {
    std::vector<std::string>::iterator it = std::remove(activeBorrowings.begin(), activeBorrowings.end(), isbn);
    activeBorrowings.erase(it, activeBorrowings.end());
}

void Member::addTransaction(const Transaction &transaction) {
    history.push_back(transaction);
}

void to_json(nlohmann::json &j, const Transaction &t) {
    j = nlohmann::json{
        {"isbn", t.isbn},
        {"action", t.action},
        {"date", t.date}
    };
}

void from_json(const nlohmann::json &j, Transaction &t) {
    t.isbn = j.value("isbn", "");
    t.action = j.value("action", "");
    t.date = j.value("date", "");
}

void to_json(nlohmann::json &j, const Book &b) {
    j = nlohmann::json{
        {"isbn", b.isbn},
        {"title", b.title},
        {"author", b.author},
        {"isAvailable", b.isAvailable}
    };
}

void from_json(const nlohmann::json &j, Book &b) {
    b.isbn = j.value("isbn", "");
    b.title = j.value("title", "");
    b.author = j.value("author", "");
    b.isAvailable = j.value("isAvailable", true);
}

void to_json(nlohmann::json &j, const Member &m) {
    j = nlohmann::json{
        {"memberId", m.memberId},
        {"name", m.name},
        {"activeBorrowings", m.activeBorrowings},
        {"history", m.history}
    };
}

void from_json(const nlohmann::json &j, Member &m) {
    m.memberId = j.value("memberId", 0);
    m.name = j.value("name", "");
    m.activeBorrowings = j.value("activeBorrowings", std::vector<std::string>());
    m.history = j.value("history", std::vector<Transaction>());
}
