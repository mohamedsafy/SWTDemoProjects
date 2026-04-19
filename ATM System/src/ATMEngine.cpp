#include "ATMEngine.h"

#include <ctime>
#include <sstream>
#include <iomanip>

static std::string buildDateTimeUTC() {
    std::time_t now = std::time(NULL);
    std::tm* utc = std::gmtime(&now);
    std::ostringstream out;
    out << std::put_time(utc, "%Y-%m-%dT%H:%M:%SZ");
    return out.str();
}

ATMEngine::ATMEngine() : insertedCard(), account(), database(), insertedAccountID(0) {
    database.connectDatabase("accounts_db.json");
}

Card ATMEngine::initiateCard(const std::string& cardNumber) {
    CardInfo cardInfo = database.fetchCardByNumber(cardNumber);
    if (!cardInfo.found) {
        insertedAccountID = 0;
        return Card();
    }
    insertedAccountID = cardInfo.accountID;
    return Card(cardInfo.cardNumber, cardInfo.accountID, cardInfo.pin);
}

BankAccount ATMEngine::initiateAccount(long accountID) {
    return database.fetchAccountByID(accountID);
}

bool ATMEngine::authenricateCard(const std::string& cardNumber, const std::string& pin) {
    insertedCard = initiateCard(cardNumber);
    if (insertedAccountID == 0) {
        return false;
    }
    if (!insertedCard.validatePin(pin)) {
        return false;
    }
    account = initiateAccount(insertedAccountID);
    return account.getOwnerName() != "";
}

bool ATMEngine::withdraw(double amount) {
    if (!account.removeFunds(amount)) {
        return false;
    }

    std::vector<Log> currentLogs = account.getLogs();
    currentLogs.push_back(Log(insertedAccountID, buildDateTimeUTC(), "withdraw", amount));

    account = BankAccount(insertedAccountID, account.getOwnerName(), account.UIBalance(), currentLogs);
    return database.updateAccount(account);
}

bool ATMEngine::deposit(double amount) {
    if (!account.addFunds(amount)) {
        return false;
    }

    std::vector<Log> currentLogs = account.getLogs();
    currentLogs.push_back(Log(insertedAccountID, buildDateTimeUTC(), "deposit", amount));

    account = BankAccount(insertedAccountID, account.getOwnerName(), account.UIBalance(), currentLogs);
    return database.updateAccount(account);
}

double ATMEngine::checkBalance() {
    return account.UIBalance();
}

std::vector<Log> ATMEngine::checkTransLog() {
    return account.getLogs();
}
