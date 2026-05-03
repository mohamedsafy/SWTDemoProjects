#include "ExpenseService.h"
#include "Utils.h"

ExpenseService::ExpenseService(ExpenseRepository& repository) : repo(repository) {}

void ExpenseService::initialize() {
    repo.load();
}

bool ExpenseService::addExpense(const std::string& description, double amount, const std::string& category) {
    if (!Utils::isValidDescription(description) || !Utils::isValidAmount(amount) ||
        !Utils::isValidCategory(category))
        return false;

    repo.add(Expense(generateId(), description, amount, category));
    repo.save();
    return true;
}

std::vector<Expense> ExpenseService::viewExpenses() {
    return repo.getAll();
}

std::vector<Expense> ExpenseService::filterByCategory(const std::string& category) {
    std::vector<Expense> out;
    if (!Utils::isValidCategory(category))
        return out;

    std::vector<Expense> all = repo.getAll();
    for (size_t i = 0; i < all.size(); ++i) {
        if (Utils::matchesCategory(all[i].getCategory(), category))
            out.push_back(all[i]);
    }
    return out;
}

bool ExpenseService::editExpense(int id, const std::string& description, double amount,
                                 const std::string& category) {
    if (!Utils::isValidDescription(description) || !Utils::isValidAmount(amount) ||
        !Utils::isValidCategory(category))
        return false;

    bool updated = repo.update(Expense(id, description, amount, category));
    if (!updated)
        return false;

    repo.save();
    return true;
}

bool ExpenseService::deleteExpense(int id) {
    bool removed = repo.remove(id);
    if (!removed)
        return false;

    repo.save();
    return true;
}

int ExpenseService::generateId() {
    std::vector<Expense> all = repo.getAll();
    int maxId = 0;
    for (size_t i = 0; i < all.size(); ++i) {
        if (all[i].getId() > maxId)
            maxId = all[i].getId();
    }
    return maxId + 1;
}
