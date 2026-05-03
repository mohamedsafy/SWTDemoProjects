#ifndef COMMAND_CONSOLE_H
#define COMMAND_CONSOLE_H

#include "CommandService.h"

class CommandConsole {
private:
    CommandService& service;

    void showMenu();

    void handleExecute();

    void handleView();

    void handleSearch();

    void handleRerun();

    void handleDelete();

public:
    explicit CommandConsole(CommandService& s) : service(s) {}

    void run();
};

#endif
