#include "ExpenseRepository.h"
#include "json.hpp"
#include <fstream>
#include <sstream>

using json = nlohmann::json;

ExpenseRepository::ExpenseRepository(const std::string& path) : filePath(path) {}

void ExpenseRepository::load() {
    expenses.clear();

    std::ifstream in(filePath.c_str());
    if (!in)
        return;

    std::stringstream buffer;
    buffer << in.rdbuf();
    std::string raw = buffer.str();
    if (raw.empty())
        return;

    try {
        json j = json::parse(raw);
        if (!j.contains("expenses") || !j["expenses"].is_array())
            return;

        for (size_t i = 0; i < j["expenses"].size(); ++i) {
            const json& item = j["expenses"][i];
            if (!item.contains("id") || !item.contains("description") || !item.contains("amount") ||
                !item.contains("category"))
                continue;
            expenses.push_back(Expense(item["id"].get<int>(),
                                       item["description"].get<std::string>(),
                                       item["amount"].get<double>(),
                                       item["category"].get<std::string>()));
        }
    } catch (...) {
        expenses.clear();
    }
}

void ExpenseRepository::save() {
    json j;
    j["expenses"] = json::array();
    for (size_t i = 0; i < expenses.size(); ++i) {
        json item;
        item["id"] = expenses[i].getId();
        item["description"] = expenses[i].getDescription();
        item["amount"] = expenses[i].getAmount();
        item["category"] = expenses[i].getCategory();
        j["expenses"].push_back(item);
    }

    std::ofstream out(filePath.c_str());
    out << j.dump(2);
}

std::vector<Expense> ExpenseRepository::getAll() const {
    return expenses;
}

void ExpenseRepository::add(const Expense& expense) {
    expenses.push_back(expense);
}

bool ExpenseRepository::remove(int id) {
    for (size_t i = 0; i < expenses.size(); ++i) {
        if (expenses[i].getId() == id) {
            expenses.erase(expenses.begin() + static_cast<std::ptrdiff_t>(i));
            return true;
        }
    }
    return false;
}

bool ExpenseRepository::update(const Expense& expense) {
    for (size_t i = 0; i < expenses.size(); ++i) {
        if (expenses[i].getId() == expense.getId()) {
            expenses[i].setDescription(expense.getDescription());
            expenses[i].setAmount(expense.getAmount());
            expenses[i].setCategory(expense.getCategory());
            return true;
        }
    }
    return false;
}
