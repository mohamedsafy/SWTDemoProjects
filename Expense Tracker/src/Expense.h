#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>

class Expense {
private:
    int id;
    std::string description;
    double amount;
    std::string category;

public:
    Expense(int id, const std::string& description, double amount, const std::string& category)
        : id(id), description(description), amount(amount), category(category) {}

    int getId() const { return id; }

    const std::string& getDescription() const { return description; }

    double getAmount() const { return amount; }

    const std::string& getCategory() const { return category; }

    void setDescription(const std::string& value) { description = value; }

    void setAmount(double value) { amount = value; }

    void setCategory(const std::string& value) { category = value; }
};

#endif
