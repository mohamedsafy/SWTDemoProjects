#ifndef UTILS_H
#define UTILS_H

#include <algorithm>
#include <cctype>
#include <string>

class Utils {
public:
    static bool isValidName(const std::string& name) {
        return hasVisibleText(name);
    }

    static bool isValidRole(const std::string& role) {
        return hasVisibleText(role);
    }

    static bool isValidSalary(double salary) {
        return salary >= 0.0;
    }

    static bool contains(const std::string& text, const std::string& keyword) {
        if (!hasVisibleText(keyword))
            return false;
        std::string lhs = toLower(text);
        std::string rhs = toLower(keyword);
        return lhs.find(rhs) != std::string::npos;
    }

private:
    static bool hasVisibleText(const std::string& value) {
        for (size_t i = 0; i < value.size(); ++i) {
            unsigned char c = static_cast<unsigned char>(value[i]);
            if (!std::isspace(c))
                return true;
        }
        return false;
    }

    static std::string toLower(const std::string& input) {
        std::string out = input;
        std::transform(out.begin(), out.end(), out.begin(), [](unsigned char c) {
            return static_cast<char>(std::tolower(c));
        });
        return out;
    }
};

#endif
