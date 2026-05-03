#include "CommandService.h"
#include "Utils.h"
#include <iostream>

void CommandService::initialize() {
    repo.load();
}

bool CommandService::executeCommand(const std::string& text) {
    if (!Utils::isValidCommand(text))
        return false;
    int id = generateId();
    std::cout << "[Simulated] Executed: " << text << std::endl;
    repo.add(Command(id, text));
    repo.save();
    return true;
}

std::vector<Command> CommandService::viewHistory() {
    return repo.getAll();
}

std::vector<Command> CommandService::search(const std::string& keyword) {
    std::vector<Command> out;
    if (!Utils::isValidCommand(keyword))
        return out;
    std::vector<Command> all = repo.getAll();
    for (size_t i = 0; i < all.size(); ++i) {
        if (Utils::contains(all[i].getText(), keyword))
            out.push_back(all[i]);
    }
    return out;
}

bool CommandService::rerun(int id) {
    std::vector<Command> all = repo.getAll();
    for (size_t i = 0; i < all.size(); ++i) {
        if (all[i].getId() == id) {
            std::cout << "[Simulated] Re-ran: " << all[i].getText() << std::endl;
            return true;
        }
    }
    return false;
}

bool CommandService::deleteCommand(int id) {
    if (!repo.remove(id))
        return false;
    repo.save();
    return true;
}

int CommandService::generateId() {
    std::vector<Command> all = repo.getAll();
    int maxId = 0;
    for (size_t i = 0; i < all.size(); ++i) {
        if (all[i].getId() > maxId)
            maxId = all[i].getId();
    }
    return maxId + 1;
}
