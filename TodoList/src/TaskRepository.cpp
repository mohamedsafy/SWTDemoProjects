#include "TaskRepository.h"
#include "json.hpp"
#include <fstream>

using json = nlohmann::json;

TaskRepository::TaskRepository(const std::string& path) : filePath(path) {}

bool TaskRepository::fileExists() const {
    std::ifstream in(filePath.c_str());
    return static_cast<bool>(in);
}

std::vector<Task> TaskRepository::loadTasks() {
    std::vector<Task> tasks;
    std::ifstream in(filePath.c_str());
    if (!in)
        return tasks;

    try {
        json data;
        in >> data;
        if (!data.contains("tasks") || !data["tasks"].is_array())
            return tasks;

        for (size_t i = 0; i < data["tasks"].size(); ++i) {
            const json& item = data["tasks"][i];
            if (!item.contains("id") || !item.contains("description") || !item.contains("completed"))
                continue;
            tasks.push_back(Task(item["id"].get<int>(),
                                 item["description"].get<std::string>(),
                                 item["completed"].get<bool>()));
        }
    } catch (...) {
        tasks.clear();
    }
    return tasks;
}

void TaskRepository::saveTasks(const std::vector<Task>& tasks) {
    json data;
    data["tasks"] = json::array();
    for (size_t i = 0; i < tasks.size(); ++i) {
        json item;
        item["id"] = tasks[i].id;
        item["description"] = tasks[i].description;
        item["completed"] = tasks[i].completed;
        data["tasks"].push_back(item);
    }

    std::ofstream out(filePath.c_str());
    out << data.dump(2);
}
