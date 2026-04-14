#ifndef UTILS_H
#define UTILS_H

#include <string>

class Utils {
public:
    static bool isValidCommand(const std::string& s) {
        for (size_t i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c != ' ' && c != '\t' && c != '\r' && c != '\n')
                return true;
        }
        return false;
    }

    static bool contains(const std::string& text, const std::string& keyword) {
        return text.find(keyword) != std::string::npos;
    }
};

#endif
