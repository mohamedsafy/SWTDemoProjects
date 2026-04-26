#ifndef EMPLOYEE_REPOSITORY_H
#define EMPLOYEE_REPOSITORY_H

#include "Employee.h"
#include <string>
#include <vector>

class EmployeeRepository {
private:
    std::vector<Employee> employees;
    std::string filePath;

public:
    explicit EmployeeRepository(const std::string& filePath);

    void load();

    void save();

    std::vector<Employee> getAll() const;

    void add(const Employee& employee);

    bool remove(int id);

    bool update(const Employee& employee);
};

#endif
