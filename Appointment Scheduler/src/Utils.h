#ifndef UTILS_H
#define UTILS_H

#include <cctype>
#include <string>

class Utils {
public:
    static bool isValidDate(std::string date) {
        if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
            return false;
        }

        for (std::size_t i = 0; i < date.size(); ++i) {
            if (i == 4 || i == 7) {
                continue;
            }
            if (!std::isdigit(static_cast<unsigned char>(date[i]))) {
                return false;
            }
        }

        int month = std::stoi(date.substr(5, 2));
        int day = std::stoi(date.substr(8, 2));
        return month >= 1 && month <= 12 && day >= 1 && day <= 31;
    }

    static bool isValidTime(std::string time) {
        if (time.size() != 5 || time[2] != ':') {
            return false;
        }

        if (!std::isdigit(static_cast<unsigned char>(time[0])) ||
            !std::isdigit(static_cast<unsigned char>(time[1])) ||
            !std::isdigit(static_cast<unsigned char>(time[3])) ||
            !std::isdigit(static_cast<unsigned char>(time[4]))) {
            return false;
        }

        int hour = std::stoi(time.substr(0, 2));
        int minute = std::stoi(time.substr(3, 2));
        return hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59;
    }
};

#endif
