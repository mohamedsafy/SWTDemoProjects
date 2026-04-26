#ifndef EXPENSE_REPOSITORY_H
#define EXPENSE_REPOSITORY_H

#include "Expense.h"
#include <string>
#include <vector>

class ExpenseRepository {
private:
    std::vector<Expense> expenses;
    std::string filePath;

public:
    explicit ExpenseRepository(const std::string& filePath);

    void load();

    void save();

    std::vector<Expense> getAll() const;

    void add(const Expense& expense);

    bool remove(int id);

    bool update(const Expense& expense);
};

#endif
