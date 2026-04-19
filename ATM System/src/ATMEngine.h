#ifndef ATM_ENGINE_H
#define ATM_ENGINE_H

#include <string>
#include <vector>
#include "AccountsDatabase.h"
#include "BankAccount.h"
#include "Card.h"

class ATMEngine {
private:
    Card insertedCard;
    BankAccount account;
    AccountsDatabase database;
    long insertedAccountID;

    Card initiateCard(const std::string& cardNumber);
    BankAccount initiateAccount(long accountID);

public:
    ATMEngine();
    bool authenricateCard(const std::string& cardNumber, const std::string& pin);
    bool withdraw(double amount);
    bool deposit(double amount);
    double checkBalance();
    std::vector<Log> checkTransLog();
};

#endif
