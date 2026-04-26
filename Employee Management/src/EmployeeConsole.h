#ifndef EMPLOYEE_CONSOLE_H
#define EMPLOYEE_CONSOLE_H

#include "EmployeeService.h"

class EmployeeConsole {
private:
    EmployeeService& service;

    void showMenu();

    void handleAdd();

    void handleView();

    void handleSearch();

    void handleUpdate();

    void handleDelete();

public:
    explicit EmployeeConsole(EmployeeService& service);

    void run();
};

#endif
