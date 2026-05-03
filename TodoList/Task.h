#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
public:
    int id;
    std::string description;
    bool completed;

    Task() : id(0), completed(false) {}
    Task(int taskId, const std::string& text, bool done)
        : id(taskId), description(text), completed(done) {}

    void markCompleted() {
        completed = true;
    }

    void updateDescription(const std::string& newDescription) {
        description = newDescription;
    }
};

#endif
