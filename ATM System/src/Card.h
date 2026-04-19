#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
private:
    std::string cardNumber;
    long accountID;
    std::string pin;

public:
    Card();
    Card(const std::string& cardNumberValue, long accountIdValue, const std::string& pinValue);
    bool validatePin(const std::string& enteredPin) const;
};

#endif
