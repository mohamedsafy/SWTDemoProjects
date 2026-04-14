#ifndef LIBRARY_CONSOLE_H
#define LIBRARY_CONSOLE_H

#include "LibraryEngine.h"

class LibraryConsole {
private:
    LibraryEngine engine;
    bool running;

public:
    explicit LibraryConsole(const std::string &dbPath);
    void run();
    void showMainMenu();
    void handleUserInput();
};

#endif
