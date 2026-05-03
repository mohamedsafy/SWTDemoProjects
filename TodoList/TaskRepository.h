#ifndef TASK_REPOSITORY_H
#define TASK_REPOSITORY_H

#include "Task.h"
#include <string>
#include <vector>

class TaskRepository {
public:
    explicit TaskRepository(const std::string& path = "tasks.json");

    std::vector<Task> loadTasks();
    void saveTasks(const std::vector<Task>& tasks);
    bool fileExists() const;

private:
    std::string filePath;
};

#endif
