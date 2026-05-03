#ifndef HOTEL_REPOSITORY_H
#define HOTEL_REPOSITORY_H

#include <string>
#include <vector>

#include "Reservation.h"
#include "Room.h"

class HotelRepository {
private:
    std::string filePath;

public:
    explicit HotelRepository(const std::string& path = "hotel.json");

    std::vector<Room> loadRooms() const;
    std::vector<Reservation> loadReservations() const;
    void saveAll(const std::vector<Room>& rooms, const std::vector<Reservation>& reservations) const;
    bool fileExists() const;
};

#endif
