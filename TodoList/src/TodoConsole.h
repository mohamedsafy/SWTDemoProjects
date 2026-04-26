#ifndef TODO_CONSOLE_H
#define TODO_CONSOLE_H

#include "InputValidator.h"
#include "TaskService.h"
#include <string>
#include <vector>

class TodoConsole {
public:
    TodoConsole(TaskService& service, InputValidator& validator);

    void run();
    void showMenu();
    void handleAddTask();
    void handleViewTasks();
    void handleCompleteTask();
    void handleEditTask();
    void handleDeleteTask();
    std::string promptDescription();
    int promptTaskId();
    void displayTasks(const std::vector<Task>& tasks);
    void displayMessage(const std::string& message);

private:
    TaskService& service;
    InputValidator& validator;
};

#endif
