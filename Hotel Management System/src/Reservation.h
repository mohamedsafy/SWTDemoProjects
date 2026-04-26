#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>

struct Reservation {
    int id;
    std::string guestName;
    int roomNumber;
    std::string date;
    std::string status;

    Reservation() : id(0), roomNumber(0) {}
    Reservation(int reservationId, const std::string& guest, int room, const std::string& bookingDate, const std::string& reservationStatus)
        : id(reservationId), guestName(guest), roomNumber(room), date(bookingDate), status(reservationStatus) {}
};

#endif
