#include "EmployeeRepository.h"
#include "json.hpp"
#include <fstream>
#include <sstream>

using json = nlohmann::json;

EmployeeRepository::EmployeeRepository(const std::string& path) : filePath(path) {}

void EmployeeRepository::load() {
    employees.clear();

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
        if (!j.contains("employees") || !j["employees"].is_array())
            return;

        for (size_t i = 0; i < j["employees"].size(); ++i) {
            const json& item = j["employees"][i];
            if (!item.contains("id") || !item.contains("name") || !item.contains("role") ||
                !item.contains("salary"))
                continue;
            employees.push_back(Employee(item["id"].get<int>(),
                                         item["name"].get<std::string>(),
                                         item["role"].get<std::string>(),
                                         item["salary"].get<double>()));
        }
    } catch (...) {
        employees.clear();
    }
}

void EmployeeRepository::save() {
    json j;
    j["employees"] = json::array();
    for (size_t i = 0; i < employees.size(); ++i) {
        json item;
        item["id"] = employees[i].getId();
        item["name"] = employees[i].getName();
        item["role"] = employees[i].getRole();
        item["salary"] = employees[i].getSalary();
        j["employees"].push_back(item);
    }

    std::ofstream out(filePath.c_str());
    out << j.dump(2);
}

std::vector<Employee> EmployeeRepository::getAll() const {
    return employees;
}

void EmployeeRepository::add(const Employee& employee) {
    employees.push_back(employee);
}

bool EmployeeRepository::remove(int id) {
    for (size_t i = 0; i < employees.size(); ++i) {
        if (employees[i].getId() == id) {
            employees.erase(employees.begin() + static_cast<std::ptrdiff_t>(i));
            return true;
        }
    }
    return false;
}

bool EmployeeRepository::update(const Employee& employee) {
    for (size_t i = 0; i < employees.size(); ++i) {
        if (employees[i].getId() == employee.getId()) {
            employees[i].setName(employee.getName());
            employees[i].setRole(employee.getRole());
            employees[i].setSalary(employee.getSalary());
            return true;
        }
    }
    return false;
}
