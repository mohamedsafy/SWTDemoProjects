#include "CommandConsole.h"
#include "Utils.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

static std::string readLine() {
    std::string line;
    if (!std::getline(std::cin, line))
        return "";
    return line;
}

static bool parseInt(const std::string& s, int& out) {
    std::istringstream iss(s);
    iss >> out;
    if (iss.fail() || !iss.eof())
        return false;
    return true;
}

static bool idExists(CommandService& svc, int id) {
    std::vector<Command> all = svc.viewHistory();
    for (size_t i = 0; i < all.size(); ++i) {
        if (all[i].getId() == id)
            return true;
    }
    return false;
}

void CommandConsole::showMenu() {
    std::cout << "\n--- Command History Manager ---\n";
    std::cout << "1. Execute Command\n";
    std::cout << "2. View Command History\n";
    std::cout << "3. Search Command\n";
    std::cout << "4. Re-run Command\n";
    std::cout << "5. Delete Command\n";
    std::cout << "6. Exit\n";
    std::cout << "Select option: ";
}

void CommandConsole::handleExecute() {
    std::cout << "Enter command: ";
    std::string text = readLine();
    if (!Utils::isValidCommand(text)) {
        std::cout << "Invalid: command cannot be empty.\n";
        return;
    }
    if (service.executeCommand(text))
        std::cout << "Command stored and persisted.\n";
    else
        std::cout << "Failed to execute command.\n";
}

void CommandConsole::handleView() {
    std::vector<Command> list = service.viewHistory();
    if (list.empty()) {
        std::cout << "(No commands in history.)\n";
        return;
    }
    for (size_t i = 0; i < list.size(); ++i) {
        std::cout << "ID: " << list[i].getId() << "  Text: " << list[i].getText() << "\n";
    }
}

void CommandConsole::handleSearch() {
    std::cout << "Enter keyword: ";
    std::string kw = readLine();
    if (!Utils::isValidCommand(kw)) {
        std::cout << "Invalid: keyword cannot be empty.\n";
        return;
    }
    std::vector<Command> list = service.search(kw);
    if (list.empty()) {
        std::cout << "No matching commands.\n";
        return;
    }
    for (size_t i = 0; i < list.size(); ++i) {
        std::cout << "ID: " << list[i].getId() << "  Text: " << list[i].getText() << "\n";
    }
}

void CommandConsole::handleRerun() {
    std::cout << "Enter command ID: ";
    std::string line = readLine();
    int id = 0;
    if (!parseInt(line, id) || id <= 0) {
        std::cout << "Invalid ID.\n";
        return;
    }
    if (!idExists(service, id)) {
        std::cout << "Invalid ID: no such command.\n";
        return;
    }
    if (service.rerun(id))
        std::cout << "Re-run completed.\n";
    else
        std::cout << "Re-run failed.\n";
}

void CommandConsole::handleDelete() {
    std::cout << "Enter command ID to delete: ";
    std::string line = readLine();
    int id = 0;
    if (!parseInt(line, id) || id <= 0) {
        std::cout << "Invalid ID.\n";
        return;
    }
    if (!idExists(service, id)) {
        std::cout << "Invalid ID: no such command.\n";
        return;
    }
    if (service.deleteCommand(id))
        std::cout << "Command deleted and file updated.\n";
    else
        std::cout << "Delete failed.\n";
}

void CommandConsole::run() {
    service.initialize();
    for (;;) {
        showMenu();
        std::string choice = readLine();
        int opt = 0;
        if (!parseInt(choice, opt)) {
            std::cout << "Invalid choice. Enter 1-6.\n";
            continue;
        }
        if (opt == 1)
            handleExecute();
        else if (opt == 2)
            handleView();
        else if (opt == 3)
            handleSearch();
        else if (opt == 4)
            handleRerun();
        else if (opt == 5)
            handleDelete();
        else if (opt == 6) {
            std::cout << "Goodbye.\n";
            break;
        } else
            std::cout << "Invalid choice. Enter 1-6.\n";
    }
}
