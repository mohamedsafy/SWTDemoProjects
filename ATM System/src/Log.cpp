#include "Log.h"

Log::Log() : accountID(0), date(""), type(""), amount(0.0) {
}

Log::Log(long accountIdValue, const std::string& dateValue, const std::string& typeValue, double amountValue)
    : accountID(accountIdValue), date(dateValue), type(typeValue), amount(amountValue) {
}
