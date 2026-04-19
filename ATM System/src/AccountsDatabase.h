#ifndef ACCOUNTS_DATABASE_H
#define ACCOUNTS_DATABASE_H

#include <string>
#include <vector>
#include "json.hpp"
#include "BankAccount.h"

struct CardInfo {
    bool found;
    long accountID;
    std::string cardNumber;
    std::string pin;
};

class AccountsDatabase {
private:
    nlohmann::json database;
    std::string databaseInfo;

    void loadDatabase();
    void writeDatabase();

public:
    AccountsDatabase();
    void connectDatabase(std::string database_info);
    CardInfo fetchCardByNumber(const std::string& cardNumber);
    BankAccount fetchAccountByID(long accountID);
    std::vector<Log> fetchAccountLogByID(long accountID);
    bool updateAccount(const BankAccount& bankAccount);
};

#endif
