#ifndef LOG_H
#define LOG_H

#include <string>

class Log {
public:
    long accountID;
    std::string date;
    std::string type;
    double amount;

    Log();
    Log(long accountIdValue, const std::string& dateValue, const std::string& typeValue, double amountValue);
};

#endif
