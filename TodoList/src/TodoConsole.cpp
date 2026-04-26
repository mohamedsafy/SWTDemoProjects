#include "TodoConsole.h"
#include <iostream>
#include <sstream>

static std::string readLine() {
    std::string line;
    if (!std::getline(std::cin, line))
        return "";
    return line;
}

static bool parseInt(const std::string& input, int& value) {
    std::istringstream stream(input);
    stream >> value;
    return !stream.fail() && stream.eof();
}

TodoConsole::TodoConsole(TaskService& svc, InputValidator& val)
    : service(svc), validator(val) {}

void TodoConsole::run() {
    service.initialize();
    for (;;) {
        showMenu();
        int choice = 0;
        if (!parseInt(readLine(), choice) || !validator.isValidMenuChoice(choice)) {
            displayMessage("Invalid choice. Enter 1-6.");
            continue;
        }

        if (choice == 1)
            handleAddTask();
        else if (choice == 2)
            handleViewTasks();
        else if (choice == 3)
            handleCompleteTask();
        else if (choice == 4)
            handleEditTask();
        else if (choice == 5)
            handleDeleteTask();
        else {
            displayMessage("Goodbye.");
            break;
        }
    }
}

void TodoConsole::showMenu() {
    std::cout << "\n--- To-Do List ---\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. View Tasks\n";
    std::cout << "3. Complete Task\n";
    std::cout << "4. Edit Task\n";
    std::cout << "5. Delete Task\n";
    std::cout << "6. Exit\n";
    std::cout << "Select option: ";
}

void TodoConsole::handleAddTask() {
    const std::string description = promptDescription();
    if (!validator.isValidDescription(description)) {
        displayMessage("Invalid description.");
        return;
    }
    Task task = service.addTask(description);
    std::cout << "Task added with ID " << task.id << ".\n";
}

void TodoConsole::handleViewTasks() {
    displayTasks(service.getTasks());
}

void TodoConsole::handleCompleteTask() {
    const int id = promptTaskId();
    if (!validator.isValidTaskId(id)) {
        displayMessage("Invalid task ID.");
        return;
    }
    displayMessage(service.completeTask(id) ? "Task completed and saved." : "Task not found.");
}

void TodoConsole::handleEditTask() {
    const int id = promptTaskId();
    std::string description = promptDescription();
    if (!validator.isValidTaskId(id) || !validator.isValidDescription(description)) {
        displayMessage("Invalid task ID or description.");
        return;
    }
    displayMessage(service.editTask(id, description) ? "Task edited and saved." : "Task not found.");
}

void TodoConsole::handleDeleteTask() {
    const int id = promptTaskId();
    if (!validator.isValidTaskId(id)) {
        displayMessage("Invalid task ID.");
        return;
    }
    displayMessage(service.deleteTask(id) ? "Task deleted and saved." : "Task not found.");
}

std::string TodoConsole::promptDescription() {
    std::cout << "Enter task description: ";
    return readLine();
}

int TodoConsole::promptTaskId() {
    std::cout << "Enter task ID: ";
    int id = 0;
    if (!parseInt(readLine(), id))
        return 0;
    return id;
}

void TodoConsole::displayTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        displayMessage("(No tasks found.)");
        return;
    }
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << "ID: " << tasks[i].id
                  << "  Description: " << tasks[i].description
                  << "  Status: " << (tasks[i].completed ? "Completed" : "Not Completed")
                  << "\n";
    }
}

void TodoConsole::displayMessage(const std::string& message) {
    std::cout << message << "\n";
}
