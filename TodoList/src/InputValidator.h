#ifndef INPUT_VALIDATOR_H
#define INPUT_VALIDATOR_H

#include <string>

class InputValidator {
public:
    bool isValidMenuChoice(int choice) const {
        return choice >= 1 && choice <= 6;
    }

    bool isValidTaskId(int taskId) const {
        return taskId > 0;
    }

    bool isValidDescription(const std::string& description) const {
        for (size_t i = 0; i < description.size(); ++i) {
            const char c = description[i];
            if (c != ' ' && c != '\t' && c != '\r' && c != '\n')
                return true;
        }
        return false;
    }
};

#endif
