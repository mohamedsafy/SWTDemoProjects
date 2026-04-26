#ifndef UTILS_H
#define UTILS_H

#include <algorithm>
#include <cctype>
#include <string>

namespace Utils {
inline bool isNonEmptyText(const std::string& value) {
    for (size_t i = 0; i < value.size(); ++i) {
        if (!std::isspace(static_cast<unsigned char>(value[i]))) {
            return true;
        }
    }
    return false;
}

inline bool isNonNegativeQuantity(int quantity) {
    return quantity >= 0;
}

inline bool isPositiveId(int id) {
    return id > 0;
}

inline std::string toLower(std::string value) {
    std::transform(value.begin(), value.end(), value.begin(),
        [](unsigned char ch) { return static_cast<char>(std::tolower(ch)); });
    return value;
}

inline bool containsIgnoreCase(const std::string& text, const std::string& query) {
    return toLower(text).find(toLower(query)) != std::string::npos;
}
}

#endif
