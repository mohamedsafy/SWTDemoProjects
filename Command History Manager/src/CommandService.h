#ifndef COMMAND_SERVICE_H
#define COMMAND_SERVICE_H

#include "Command.h"
#include "CommandRepository.h"
#include <string>
#include <vector>

class CommandService {
private:
    CommandRepository& repo;

public:
    explicit CommandService(CommandRepository& r) : repo(r) {}

    void initialize();

    bool executeCommand(const std::string& text);

    std::vector<Command> viewHistory();

    std::vector<Command> search(const std::string& keyword);

    bool rerun(int id);

    bool deleteCommand(int id);

    int generateId();
};

#endif
