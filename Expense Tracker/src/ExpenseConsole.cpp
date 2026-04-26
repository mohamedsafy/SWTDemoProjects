#include "ExpenseConsole.h"
#include "Utils.h"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

static std::string readLine() {
    std::string line;
    if (!std::getline(std::cin, line))
        return "";
    return line;
}

static bool parseInt(const std::string& input, int& out) {
    std::istringstream iss(input);
    iss >> out;
    return !iss.fail() && iss.eof();
}

static bool parseDouble(const std::string& input, double& out) {
    std::istringstream iss(input);
    iss >> out;
    return !iss.fail() && iss.eof();
}

static void printExpenses(const std::vector<Expense>& expenses) {
    if (expenses.empty()) {
        std::cout << "(No expenses found.)\n";
        return;
    }

    for (size_t i = 0; i < expenses.size(); ++i) {
        std::cout << "ID: " << expenses[i].getId()
                  << "  Description: " << expenses[i].getDescription()
                  << "  Amount: " << std::fixed << std::setprecision(2) << expenses[i].getAmount()
                  << "  Category: " << expenses[i].getCategory() << "\n";
    }
}

ExpenseConsole::ExpenseConsole(ExpenseService& svc) : service(svc) {}

void ExpenseConsole::showMenu() {
    std::cout << "\n--- Expense Tracker ---\n";
    std::cout << "1. Add Expense\n";
    std::cout << "2. View Expenses\n";
    std::cout << "3. Filter Expenses by Category\n";
    std::cout << "4. Edit Expense\n";
    std::cout << "5. Delete Expense\n";
    std::cout << "6. Exit\n";
    std::cout << "Select option: ";
}

void ExpenseConsole::handleAdd() {
    std::cout << "Enter description: ";
    std::string description = readLine();
    std::cout << "Enter amount: ";
    std::string amountLine = readLine();
    std::cout << "Enter category: ";
    std::string category = readLine();

    double amount = 0.0;
    if (!parseDouble(amountLine, amount)) {
        std::cout << "Invalid amount.\n";
        return;
    }

    if (service.addExpense(description, amount, category))
        std::cout << "Expense added and saved.\n";
    else
        std::cout << "Failed to add expense. Check description, amount, and category.\n";
}

void ExpenseConsole::handleView() {
    printExpenses(service.viewExpenses());
}

void ExpenseConsole::handleFilter() {
    std::cout << "Enter category: ";
    std::string category = readLine();
    if (!Utils::isValidCategory(category)) {
        std::cout << "Invalid category.\n";
        return;
    }

    printExpenses(service.filterByCategory(category));
}

void ExpenseConsole::handleEdit() {
    std::cout << "Enter expense ID to edit: ";
    std::string idLine = readLine();
    int id = 0;
    if (!parseInt(idLine, id) || id <= 0) {
        std::cout << "Invalid ID.\n";
        return;
    }

    std::cout << "Enter new description: ";
    std::string description = readLine();
    std::cout << "Enter new amount: ";
    std::string amountLine = readLine();
    std::cout << "Enter new category: ";
    std::string category = readLine();

    double amount = 0.0;
    if (!parseDouble(amountLine, amount)) {
        std::cout << "Invalid amount.\n";
        return;
    }

    if (service.editExpense(id, description, amount, category))
        std::cout << "Expense updated and saved.\n";
    else
        std::cout << "Update failed: invalid ID or input.\n";
}

void ExpenseConsole::handleDelete() {
    std::cout << "Enter expense ID to delete: ";
    std::string idLine = readLine();
    int id = 0;
    if (!parseInt(idLine, id) || id <= 0) {
        std::cout << "Invalid ID.\n";
        return;
    }

    if (service.deleteExpense(id))
        std::cout << "Expense deleted and saved.\n";
    else
        std::cout << "Delete failed: invalid ID.\n";
}

void ExpenseConsole::run() {
    service.initialize();

    for (;;) {
        showMenu();
        std::string choice = readLine();
        int option = 0;
        if (!parseInt(choice, option)) {
            std::cout << "Invalid choice. Enter 1-6.\n";
            continue;
        }

        if (option == 1)
            handleAdd();
        else if (option == 2)
            handleView();
        else if (option == 3)
            handleFilter();
        else if (option == 4)
            handleEdit();
        else if (option == 5)
            handleDelete();
        else if (option == 6) {
            std::cout << "Goodbye.\n";
            break;
        } else
            std::cout << "Invalid choice. Enter 1-6.\n";
    }
}
