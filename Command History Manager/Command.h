#ifndef COMMAND_H
#define COMMAND_H

#include <string>

class Command {
private:
    int id;
    std::string text;

public:
    Command(int id, const std::string& text) : id(id), text(text) {}

    int getId() const { return id; }

    const std::string& getText() const { return text; }
};

#endif
