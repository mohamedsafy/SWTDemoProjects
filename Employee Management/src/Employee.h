#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
private:
    int id;
    std::string name;
    std::string role;
    double salary;

public:
    Employee(int id, const std::string& name, const std::string& role, double salary)
        : id(id), name(name), role(role), salary(salary) {}

    int getId() const { return id; }

    const std::string& getName() const { return name; }

    const std::string& getRole() const { return role; }

    double getSalary() const { return salary; }

    void setName(const std::string& value) { name = value; }

    void setRole(const std::string& value) { role = value; }

    void setSalary(double value) { salary = value; }
};

#endif
