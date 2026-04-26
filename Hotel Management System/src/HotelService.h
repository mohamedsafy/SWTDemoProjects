#ifndef HOTEL_SERVICE_H
#define HOTEL_SERVICE_H

#include <vector>

#include "HotelRepository.h"

class HotelService {
private:
    std::vector<Room> rooms;
    std::vector<Reservation> reservations;
    int nextReservationId;

public:
    HotelService();

    void initialize(HotelRepository& repository);
    Reservation bookRoom(const std::string& guestName, int roomNumber, const std::string& date, HotelRepository& repository);
    bool checkInGuest(int reservationId, HotelRepository& repository);
    bool checkOutGuest(int reservationId, HotelRepository& repository);
    bool cancelReservation(int reservationId, HotelRepository& repository);
    std::vector<Room> getRooms() const;
    bool roomExists(int roomNumber) const;
    bool isRoomAvailable(int roomNumber) const;
    bool reservationExists(int reservationId) const;
    bool validateBookingInput(const std::string& guestName, int roomNumber, const std::string& date) const;
};

#endif
