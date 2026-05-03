#ifndef TASK_SERVICE_H
#define TASK_SERVICE_H

#include "Task.h"
#include "TaskRepository.h"
#include <vector>

class TaskService {
public:
    explicit TaskService(TaskRepository& repository);

    void initialize();
    std::vector<Task> getTasks() const;
    Task addTask(const std::string& description);
    bool completeTask(int taskId);
    bool editTask(int taskId, const std::string& newDescription);
    bool deleteTask(int taskId);
    bool taskExists(int taskId);

private:
    std::vector<Task> tasks;
    TaskRepository& repository;
    int nextId;

    Task* findTaskById(int taskId);
    int calculateNextId() const;
    void persistTasks();
};

#endif
