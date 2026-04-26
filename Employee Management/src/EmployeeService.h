#ifndef EMPLOYEE_SERVICE_H
#define EMPLOYEE_SERVICE_H

#include "EmployeeRepository.h"
#include <string>
#include <vector>

class EmployeeService {
private:
    EmployeeRepository& repo;

public:
    explicit EmployeeService(EmployeeRepository& repo);

    void initialize();

    bool addEmployee(const std::string& name, const std::string& role, double salary);

    std::vector<Employee> viewEmployees();

    std::vector<Employee> search(const std::string& keyword);

    bool updateEmployee(int id, const std::string& name, const std::string& role, double salary);

    bool deleteEmployee(int id);

    int generateId();
};

#endif
