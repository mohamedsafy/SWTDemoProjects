#include "TaskService.h"
#include <algorithm>

TaskService::TaskService(TaskRepository& repo) : repository(repo), nextId(1) {}

void TaskService::initialize() {
    tasks = repository.loadTasks();
    nextId = calculateNextId();
}

std::vector<Task> TaskService::getTasks() const {
    return tasks;
}

Task TaskService::addTask(const std::string& description) {
    Task task(nextId++, description, false);
    tasks.push_back(task);
    persistTasks();
    return task;
}

bool TaskService::completeTask(int taskId) {
    Task* task = findTaskById(taskId);
    if (!task)
        return false;
    task->markCompleted();
    persistTasks();
    return true;
}

bool TaskService::editTask(int taskId, const std::string& newDescription) {
    Task* task = findTaskById(taskId);
    if (!task)
        return false;
    task->updateDescription(newDescription);
    persistTasks();
    return true;
}

bool TaskService::deleteTask(int taskId) {
    for (size_t i = 0; i < tasks.size(); ++i) {
        if (tasks[i].id == taskId) {
            tasks.erase(tasks.begin() + static_cast<std::ptrdiff_t>(i));
            persistTasks();
            return true;
        }
    }
    return false;
}

bool TaskService::taskExists(int taskId) {
    return findTaskById(taskId) != 0;
}

Task* TaskService::findTaskById(int taskId) {
    for (size_t i = 0; i < tasks.size(); ++i) {
        if (tasks[i].id == taskId)
            return &tasks[i];
    }
    return 0;
}

int TaskService::calculateNextId() const {
    int largest = 0;
    for (size_t i = 0; i < tasks.size(); ++i)
        largest = std::max(largest, tasks[i].id);
    return largest + 1;
}

void TaskService::persistTasks() {
    repository.saveTasks(tasks);
}
