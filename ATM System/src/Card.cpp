#include "Card.h"

Card::Card() : cardNumber(""), accountID(0), pin("") {
}

Card::Card(const std::string& cardNumberValue, long accountIdValue, const std::string& pinValue)
    : cardNumber(cardNumberValue), accountID(accountIdValue), pin(pinValue) {
}

bool Card::validatePin(const std::string& enteredPin) const {
    return pin == enteredPin;
}
