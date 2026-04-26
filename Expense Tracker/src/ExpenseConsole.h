#ifndef EXPENSE_CONSOLE_H
#define EXPENSE_CONSOLE_H

#include "ExpenseService.h"

class ExpenseConsole {
private:
    ExpenseService& service;

public:
    explicit ExpenseConsole(ExpenseService& service);

    void run();

    void showMenu();

    void handleAdd();

    void handleView();

    void handleFilter();

    void handleEdit();

    void handleDelete();
};

#endif
