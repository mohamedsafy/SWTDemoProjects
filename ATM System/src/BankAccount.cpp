#include "BankAccount.h"

BankAccount::BankAccount() : id(0), ownerName(""), balance(0.0), logs() {
}

BankAccount::BankAccount(long idValue, const std::string& ownerNameValue, double balanceValue, const std::vector<Log>& logsValue)
    : id(idValue), ownerName(ownerNameValue), balance(balanceValue), logs(logsValue) {
}

std::string BankAccount::getOwnerName() const {
    return ownerName;
}

double BankAccount::UIBalance() const {
    return balance;
}

bool BankAccount::addFunds(double amount) {
    if (amount <= 0.0) {
        return false;
    }
    balance = balance + amount;
    return true;
}

bool BankAccount::removeFunds(double amount) {
    if (amount <= 0.0) {
        return false;
    }
    if (amount > balance) {
        return false;
    }
    balance = balance - amount;
    return true;
}

std::vector<Log> BankAccount::getLogs() const {
    return logs;
}

bool BankAccount::updateBalance(double new_balance) {
    if (new_balance < 0.0) {
        return false;
    }
    balance = new_balance;
    return true;
}
