#include "EmployeeConsole.h"
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

static void printEmployees(const std::vector<Employee>& employees) {
    for (size_t i = 0; i < employees.size(); ++i) {
        std::cout << "ID: " << employees[i].getId()
                  << "  Name: " << employees[i].getName()
                  << "  Role: " << employees[i].getRole()
                  << "  Salary: " << std::fixed << std::setprecision(2) << employees[i].getSalary()
                  << "\n";
    }
}

EmployeeConsole::EmployeeConsole(EmployeeService& svc) : service(svc) {}

void EmployeeConsole::showMenu() {
    std::cout << "\n--- Employee Management System ---\n";
    std::cout << "1. Add Employee\n";
    std::cout << "2. View Employees\n";
    std::cout << "3. Search Employee\n";
    std::cout << "4. Update Employee\n";
    std::cout << "5. Delete Employee\n";
    std::cout << "6. Exit\n";
    std::cout << "Select option: ";
}

void EmployeeConsole::handleAdd() {
    std::cout << "Enter employee name: ";
    std::string name = readLine();
    std::cout << "Enter employee role: ";
    std::string role = readLine();
    std::cout << "Enter employee salary: ";
    std::string salaryLine = readLine();

    double salary = 0.0;
    if (!Utils::isValidName(name) || !Utils::isValidRole(role) || !parseDouble(salaryLine, salary) ||
        !Utils::isValidSalary(salary)) {
        std::cout << "Invalid employee details.\n";
        return;
    }

    if (service.addEmployee(name, role, salary))
        std::cout << "Employee added and saved.\n";
    else
        std::cout << "Failed to add employee.\n";
}

void EmployeeConsole::handleView() {
    std::vector<Employee> employees = service.viewEmployees();
    if (employees.empty()) {
        std::cout << "(No employees found.)\n";
        return;
    }
    printEmployees(employees);
}

void EmployeeConsole::handleSearch() {
    std::cout << "Enter employee name or part of name: ";
    std::string keyword = readLine();
    if (!Utils::isValidName(keyword)) {
        std::cout << "Invalid keyword.\n";
        return;
    }

    std::vector<Employee> matches = service.search(keyword);
    if (matches.empty()) {
        std::cout << "No matching employees.\n";
        return;
    }
    printEmployees(matches);
}

void EmployeeConsole::handleUpdate() {
    std::cout << "Enter employee ID to update: ";
    std::string idLine = readLine();
    int id = 0;
    if (!parseInt(idLine, id) || id <= 0) {
        std::cout << "Invalid ID.\n";
        return;
    }

    std::cout << "Enter new employee name: ";
    std::string name = readLine();
    std::cout << "Enter new employee role: ";
    std::string role = readLine();
    std::cout << "Enter new employee salary: ";
    std::string salaryLine = readLine();

    double salary = 0.0;
    if (!Utils::isValidName(name) || !Utils::isValidRole(role) || !parseDouble(salaryLine, salary) ||
        !Utils::isValidSalary(salary)) {
        std::cout << "Invalid employee details.\n";
        return;
    }

    if (service.updateEmployee(id, name, role, salary))
        std::cout << "Employee updated and saved.\n";
    else
        std::cout << "Update failed: invalid ID.\n";
}

void EmployeeConsole::handleDelete() {
    std::cout << "Enter employee ID to delete: ";
    std::string idLine = readLine();
    int id = 0;
    if (!parseInt(idLine, id) || id <= 0) {
        std::cout << "Invalid ID.\n";
        return;
    }

    if (service.deleteEmployee(id))
        std::cout << "Employee deleted and saved.\n";
    else
        std::cout << "Delete failed: invalid ID.\n";
}

void EmployeeConsole::run() {
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
            handleSearch();
        else if (option == 4)
            handleUpdate();
        else if (option == 5)
            handleDelete();
        else if (option == 6) {
            std::cout << "Goodbye.\n";
            break;
        } else
            std::cout << "Invalid choice. Enter 1-6.\n";
    }
}
