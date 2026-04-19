#include "AccountsDatabase.h"

#include <fstream>

AccountsDatabase::AccountsDatabase() : database(), databaseInfo("accounts_db.json") {
}

void AccountsDatabase::connectDatabase(std::string database_info) {
    databaseInfo = database_info;
    loadDatabase();
}

void AccountsDatabase::loadDatabase() {
    std::ifstream in(databaseInfo.c_str());
    if (!in.is_open()) {
        nlohmann::json defaultDb = nlohmann::json::array();

        nlohmann::json first;
        first["accountId"] = 1000;
        first["ownerName"] = "John Doe";
        first["balance"] = 1500.75;
        first["card"]["cardNumber"] = "1234567812345678";
        first["card"]["pin"] = "1234";
        first["logs"] = nlohmann::json::array();

        nlohmann::json second;
        second["accountId"] = 1001;
        second["ownerName"] = "Jane Smith";
        second["balance"] = 800.50;
        second["card"]["cardNumber"] = "8765432187654321";
        second["card"]["pin"] = "4321";
        second["logs"] = nlohmann::json::array();

        defaultDb.push_back(first);
        defaultDb.push_back(second);
        database = defaultDb;
        writeDatabase();
        return;
    }

    in >> database;
    in.close();

    if (!database.is_array()) {
        database = nlohmann::json::array();
        writeDatabase();
    }
}

void AccountsDatabase::writeDatabase() {
    std::ofstream out(databaseInfo.c_str());
    out << database.dump(4);
    out.close();
}

CardInfo AccountsDatabase::fetchCardByNumber(const std::string& cardNumber) {
    CardInfo result;
    result.found = false;
    result.accountID = 0;
    result.cardNumber = "";
    result.pin = "";

    int i = 0;
    for (i = 0; i < static_cast<int>(database.size()); i++) {
        nlohmann::json accountObj = database[i];
        if (accountObj.contains("card") && accountObj["card"].contains("cardNumber")) {
            std::string dbCard = accountObj["card"]["cardNumber"];
            if (dbCard == cardNumber) {
                result.found = true;
                result.accountID = accountObj["accountId"];
                result.cardNumber = dbCard;
                result.pin = accountObj["card"]["pin"];
                return result;
            }
        }
    }

    return result;
}

BankAccount AccountsDatabase::fetchAccountByID(long accountID) {
    int i = 0;
    for (i = 0; i < static_cast<int>(database.size()); i++) {
        nlohmann::json accountObj = database[i];
        if (accountObj["accountId"] == accountID) {
            std::vector<Log> logs;
            int j = 0;
            for (j = 0; j < static_cast<int>(accountObj["logs"].size()); j++) {
                nlohmann::json logObj = accountObj["logs"][j];
                logs.push_back(Log(logObj["accountId"], logObj["date"], logObj["type"], logObj["amount"]));
            }
            return BankAccount(accountObj["accountId"], accountObj["ownerName"], accountObj["balance"], logs);
        }
    }

    return BankAccount();
}

std::vector<Log> AccountsDatabase::fetchAccountLogByID(long accountID) {
    BankAccount account = fetchAccountByID(accountID);
    return account.getLogs();
}

bool AccountsDatabase::updateAccount(const BankAccount& bankAccount) {
    int i = 0;
    for (i = 0; i < static_cast<int>(database.size()); i++) {
        if (database[i]["ownerName"] == bankAccount.getOwnerName()) {
            database[i]["balance"] = bankAccount.UIBalance();

            std::vector<Log> logs = bankAccount.getLogs();
            nlohmann::json logsJson = nlohmann::json::array();
            int j = 0;
            for (j = 0; j < static_cast<int>(logs.size()); j++) {
                nlohmann::json logObj;
                logObj["accountId"] = logs[j].accountID;
                logObj["date"] = logs[j].date;
                logObj["type"] = logs[j].type;
                logObj["amount"] = logs[j].amount;
                logsJson.push_back(logObj);
            }
            database[i]["logs"] = logsJson;
            writeDatabase();
            return true;
        }
    }
    return false;
}
