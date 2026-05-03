#ifndef EXPENSE_SERVICE_H
#define EXPENSE_SERVICE_H

#include "ExpenseRepository.h"
#include <string>
#include <vector>

class ExpenseService {
private:
    ExpenseRepository& repo;

public:
    explicit ExpenseService(ExpenseRepository& repo);

    void initialize();

    bool addExpense(const std::string& description, double amount, const std::string& category);

    std::vector<Expense> viewExpenses();

    std::vector<Expense> filterByCategory(const std::string& category);

    bool editExpense(int id, const std::string& description, double amount, const std::string& category);

    bool deleteExpense(int id);

    int generateId();
};

#endif
