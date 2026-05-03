#ifndef COMMAND_REPOSITORY_H
#define COMMAND_REPOSITORY_H

#include "Command.h"
#include <string>
#include <vector>

class CommandRepository {
private:
    std::vector<Command> commands;
    std::string filePath;

public:
    explicit CommandRepository(const std::string& path);

    void load();

    void save();

    std::vector<Command> getAll() const;

    void add(const Command& cmd);

    bool remove(int id);
};

#endif
