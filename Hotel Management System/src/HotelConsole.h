#ifndef HOTEL_CONSOLE_H
#define HOTEL_CONSOLE_H

#include <string>

#include "HotelService.h"

class HotelConsole {
private:
    HotelService& service;

public:
    explicit HotelConsole(HotelService& hotelService);

    void run();
    void showMenu() const;
    void bookRoom();
    void checkInGuest();
    void checkOutGuest();
    void cancelReservation();
    void viewRoomAvailability();
    int readInt(const std::string& prompt) const;
    std::string readString(const std::string& prompt) const;
};

#endif
