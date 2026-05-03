#include "LibraryEngine.h"
#include <algorithm>
#include <cctype>
#include <ctime>

LibraryEngine::LibraryEngine(const std::string &dbPath)
    : db(dbPath), hasSession(false) {
    db.loadData();
}

bool LibraryEngine::login(int memberId) {
    Member member;
    if (!db.getMemberById(memberId, member)) {
        hasSession = false;
        return false;
    }
    currentMember = member;
    hasSession = true;
    return true;
}

std::vector<Book> LibraryEngine::searchBooks(const std::string &query) {
    std::vector<Book> allBooks = db.getAllBooks();
    std::vector<Book> matched;
    std::string key = toLower(query);
    std::vector<Book>::iterator it;
    for (it = allBooks.begin(); it != allBooks.end(); ++it) {
        std::string title = toLower(it->title);
        std::string isbn = toLower(it->isbn);
        if (title.find(key) != std::string::npos || isbn.find(key) != std::string::npos) {
            matched.push_back(*it);
        }
    }
    return matched;
}

bool LibraryEngine::borrowBook(const std::string &isbn) {
    if (!hasSession) {
        return false;
    }

    Book book;
    if (!db.getBookByISBN(isbn, book) || !book.isAvailable) {
        return false;
    }

    book.markBorrowed();
    currentMember.addBorrowedBook(isbn);
    Transaction transaction;
    transaction.isbn = isbn;
    transaction.action = "borrow";
    transaction.date = getCurrentDate();
    currentMember.addTransaction(transaction);

    if (!db.updateBook(book) || !db.updateMember(currentMember)) {
        return false;
    }
    db.addTransaction(transaction);
    return db.saveData();
}

bool LibraryEngine::returnBook(const std::string &isbn) {
    if (!hasSession) {
        return false;
    }

    std::vector<std::string>::const_iterator own =
        std::find(currentMember.activeBorrowings.begin(), currentMember.activeBorrowings.end(), isbn);
    if (own == currentMember.activeBorrowings.end()) {
        return false;
    }

    Book book;
    if (!db.getBookByISBN(isbn, book)) {
        return false;
    }

    book.markReturned();
    currentMember.removeBorrowedBook(isbn);
    Transaction transaction;
    transaction.isbn = isbn;
    transaction.action = "return";
    transaction.date = getCurrentDate();
    currentMember.addTransaction(transaction);

    if (!db.updateBook(book) || !db.updateMember(currentMember)) {
        return false;
    }
    db.addTransaction(transaction);
    return db.saveData();
}

std::vector<Transaction> LibraryEngine::getBorrowingHistory() const {
    if (!hasSession) {
        return std::vector<Transaction>();
    }
    return currentMember.history;
}

std::vector<Book> LibraryEngine::getAvailableBooks() {
    std::vector<Book> allBooks = db.getAllBooks();
    std::vector<Book> available;
    std::vector<Book>::iterator it;
    for (it = allBooks.begin(); it != allBooks.end(); ++it) {
        if (it->isAvailable) {
            available.push_back(*it);
        }
    }
    return available;
}

std::vector<std::string> LibraryEngine::getBorrowedBooks() const {
    if (!hasSession) {
        return std::vector<std::string>();
    }
    return currentMember.activeBorrowings;
}

std::string LibraryEngine::getCurrentDate() const {
    std::time_t now = std::time(0);
    std::tm *local = std::localtime(&now);
    char buffer[11];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", local);
    return std::string(buffer);
}

std::string LibraryEngine::toLower(const std::string &value) const {
    std::string out = value;
    std::string::iterator it;
    for (it = out.begin(); it != out.end(); ++it) {
        *it = static_cast<char>(std::tolower(*it));
    }
    return out;
}
