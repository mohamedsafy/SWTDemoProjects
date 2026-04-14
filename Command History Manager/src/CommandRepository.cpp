#include "CommandRepository.h"
#include "json.hpp"
#include <fstream>
#include <sstream>

using json = nlohmann::json;

CommandRepository::CommandRepository(const std::string& path) : filePath(path) {}

void CommandRepository::load() {
    commands.clear();
    std::ifstream in(filePath.c_str());
    if (!in)
        return;
    std::stringstream buffer;
    buffer << in.rdbuf();
    std::string raw = buffer.str();
    if (raw.empty())
        return;
    try {
        json j = json::parse(raw);
        if (!j.contains("commands") || !j["commands"].is_array())
            return;
        for (size_t i = 0; i < j["commands"].size(); ++i) {
            const json& item = j["commands"][i];
            if (!item.contains("id") || !item.contains("text"))
                continue;
            int id = item["id"].get<int>();
            std::string text = item["text"].get<std::string>();
            commands.push_back(Command(id, text));
        }
    } catch (...) {
        commands.clear();
    }
}

void CommandRepository::save() {
    json j;
    j["commands"] = json::array();
    for (size_t i = 0; i < commands.size(); ++i) {
        json item;
        item["id"] = commands[i].getId();
        item["text"] = commands[i].getText();
        j["commands"].push_back(item);
    }
    std::ofstream out(filePath.c_str());
    out << j.dump(2);
}

std::vector<Command> CommandRepository::getAll() const {
    return commands;
}

void CommandRepository::add(const Command& cmd) {
    commands.push_back(cmd);
}

bool CommandRepository::remove(int id) {
    for (size_t i = 0; i < commands.size(); ++i) {
        if (commands[i].getId() == id) {
            commands.erase(commands.begin() + static_cast<std::ptrdiff_t>(i));
            return true;
        }
    }
    return false;
}
