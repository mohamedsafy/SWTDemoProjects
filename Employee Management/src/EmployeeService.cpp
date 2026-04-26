#include "EmployeeService.h"
#include "Utils.h"

EmployeeService::EmployeeService(EmployeeRepository& repository) : repo(repository) {}

void EmployeeService::initialize() {
    repo.load();
}

bool EmployeeService::addEmployee(const std::string& name, const std::string& role, double salary) {
    if (!Utils::isValidName(name) || !Utils::isValidRole(role) || !Utils::isValidSalary(salary))
        return false;

    repo.add(Employee(generateId(), name, role, salary));
    repo.save();
    return true;
}

std::vector<Employee> EmployeeService::viewEmployees() {
    return repo.getAll();
}

std::vector<Employee> EmployeeService::search(const std::string& keyword) {
    std::vector<Employee> matches;
    if (!Utils::isValidName(keyword))
        return matches;

    std::vector<Employee> all = repo.getAll();
    for (size_t i = 0; i < all.size(); ++i) {
        if (Utils::contains(all[i].getName(), keyword))
            matches.push_back(all[i]);
    }
    return matches;
}

bool EmployeeService::updateEmployee(int id, const std::string& name, const std::string& role,
                                     double salary) {
    if (!Utils::isValidName(name) || !Utils::isValidRole(role) || !Utils::isValidSalary(salary))
        return false;

    if (!repo.update(Employee(id, name, role, salary)))
        return false;

    repo.save();
    return true;
}

bool EmployeeService::deleteEmployee(int id) {
    if (!repo.remove(id))
        return false;

    repo.save();
    return true;
}

int EmployeeService::generateId() {
    std::vector<Employee> all = repo.getAll();
    int maxId = 0;
    for (size_t i = 0; i < all.size(); ++i) {
        if (all[i].getId() > maxId)
            maxId = all[i].getId();
    }
    return maxId + 1;
}
