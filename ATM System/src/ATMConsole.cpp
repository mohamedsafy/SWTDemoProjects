#include "ATMConsole.h"

#include <iostream>
#include <iomanip>
#include <limits>
#include <cctype>

static bool isExactDigits(const std::string& value, int expectedLength) {
    if (static_cast<int>(value.size()) != expectedLength) {
        return false;
    }
    int i = 0;
    for (i = 0; i < expectedLength; i++) {
        if (!std::isdigit(static_cast<unsigned char>(value[i]))) {
            return false;
        }
    }
    return true;
}

static bool readAmount(double& amount) {
    std::cin >> amount;
    if (!std::cin.good()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return true;
}

void ATMConsole::consoleInterfaceStart(void) {
    std::cout << "=== Welcome to ATM Console ===" << std::endl;

    bool authenticated = false;
    while (!authenticated) {
        std::string cardNumber;
        std::string pin;

        std::cout << "Enter your 16-digit card number: ";
        std::getline(std::cin, cardNumber);
        std::cout << "Enter your 4-digit PIN: ";
        std::getline(std::cin, pin);

        if (!isExactDigits(cardNumber, 16) || !isExactDigits(pin, 4)) {
            std::cout << "Invalid card number or PIN. Try again." << std::endl;
            continue;
        }

        authenticated = engine.authenricateCard(cardNumber, pin);
        if (!authenticated) {
            std::cout << "Invalid card number or PIN. Try again." << std::endl;
        }
    }

    bool running = true;
    while (running) {
        int option = 0;
        std::cout << std::endl;
        std::cout << "1. Check Balance" << std::endl;
        std::cout << "2. Withdraw Money" << std::endl;
        std::cout << "3. Deposit Money" << std::endl;
        std::cout << "4. Check Transaction Logs" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Choose option: ";

        std::cin >> option;
        if (!std::cin.good()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid option." << std::endl;
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (option == 1) {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Current balance: " << engine.checkBalance() << std::endl;
        } else if (option == 2) {
            consoleWithdrawMenu();
        } else if (option == 3) {
            consoleDepositMenu();
        } else if (option == 4) {
            consoleTransLogsMenu();
        } else if (option == 5) {
            running = false;
            std::cout << "Thank you for using the ATM." << std::endl;
        } else {
            std::cout << "Invalid option." << std::endl;
        }
    }
}

void ATMConsole::consoleWithdrawMenu(void) {
    double amount = 0.0;
    std::cout << "Enter withdrawal amount: ";
    if (!readAmount(amount) || amount <= 0.0) {
        std::cout << "Invalid amount." << std::endl;
        return;
    }

    bool ok = engine.withdraw(amount);
    if (!ok) {
        std::cout << "Insufficient funds or invalid amount." << std::endl;
        return;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Withdrawal successful." << std::endl;
    std::cout << "New balance: " << engine.checkBalance() << std::endl;
}

void ATMConsole::consoleDepositMenu(void) {
    double amount = 0.0;
    std::cout << "Enter deposit amount: ";
    if (!readAmount(amount) || amount <= 0.0) {
        std::cout << "Invalid amount." << std::endl;
        return;
    }

    bool ok = engine.deposit(amount);
    if (!ok) {
        std::cout << "Unable to process deposit." << std::endl;
        return;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Deposit successful." << std::endl;
    std::cout << "New balance: " << engine.checkBalance() << std::endl;
}

void ATMConsole::consoleTransLogsMenu(void) {
    std::vector<Log> logs = engine.checkTransLog();
    if (logs.empty()) {
        std::cout << "No transaction logs found." << std::endl;
        return;
    }

    std::cout << "Transaction Logs:" << std::endl;
    int i = 0;
    for (i = 0; i < static_cast<int>(logs.size()); i++) {
        std::cout << logs[i].date << " | " << logs[i].type << " | " << std::fixed << std::setprecision(2) << logs[i].amount << std::endl;
    }
}
