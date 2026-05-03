#ifndef UTILS_H
#define UTILS_H

#include <algorithm>
#include <cctype>
#include <string>

class Utils {
public:
    static bool isValidDescription(const std::string& description) {
        return hasVisibleText(description);
    }

    static bool isValidAmount(double amount) {
        return amount > 0.0;
    }

    static bool isValidCategory(const std::string& category) {
        return hasVisibleText(category);
    }

    static bool matchesCategory(const std::string& expenseCategory, const std::string& category) {
        return toLower(expenseCategory) == toLower(category);
    }

private:
    static bool hasVisibleText(const std::string& text) {
        for (size_t i = 0; i < text.size(); ++i) {
            unsigned char c = static_cast<unsigned char>(text[i]);
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
