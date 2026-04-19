#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>
#include <vector>
#include "Log.h"

class BankAccount {
private:
    long id;
    std::string ownerName;
    double balance;
    std::vector<Log> logs;

public:
    BankAccount();
    BankAccount(long idValue, const std::string& ownerNameValue, double balanceValue, const std::vector<Log>& logsValue);

    std::string getOwnerName() const;
    double UIBalance() const;
    bool addFunds(double amount);
    bool removeFunds(double amount);
    std::vector<Log> getLogs() const;
    bool updateBalance(double new_balance);
};

#endif
