#include "HotelService.h"

#include <cctype>
#include <stdexcept>

namespace {
bool isDigits(const std::string& value) {
    if (value.empty()) {
        return false;
    }
    for (std::size_t i = 0; i < value.size(); ++i) {
        if (!std::isdigit(static_cast<unsigned char>(value[i]))) {
            return false;
        }
    }
    return true;
}
}

HotelService::HotelService() : nextReservationId(1) {}

void HotelService::initialize(HotelRepository& repository) {
    rooms = repository.loadRooms();
    reservations = repository.loadReservations();
    nextReservationId = 1;

    for (std::size_t i = 0; i < reservations.size(); ++i) {
        if (reservations[i].id >= nextReservationId) {
            nextReservationId = reservations[i].id + 1;
        }
    }
}

Reservation HotelService::bookRoom(const std::string& guestName, int roomNumber, const std::string& date, HotelRepository& repository) {
    if (!validateBookingInput(guestName, roomNumber, date)) {
        throw std::runtime_error("Invalid booking input.");
    }
    if (!roomExists(roomNumber)) {
        throw std::runtime_error("Room number does not exist.");
    }
    if (!isRoomAvailable(roomNumber)) {
        throw std::runtime_error("Room is not available.");
    }

    for (std::size_t i = 0; i < rooms.size(); ++i) {
        if (rooms[i].roomNumber == roomNumber) {
            rooms[i].isAvailable = false;
            break;
        }
    }

    Reservation reservation(nextReservationId++, guestName, roomNumber, date, "Booked");
    reservations.push_back(reservation);
    repository.saveAll(rooms, reservations);
    return reservation;
}

bool HotelService::checkInGuest(int reservationId, HotelRepository& repository) {
    for (std::size_t i = 0; i < reservations.size(); ++i) {
        if (reservations[i].id == reservationId && reservations[i].status == "Booked") {
            for (std::size_t j = 0; j < rooms.size(); ++j) {
                if (rooms[j].roomNumber == reservations[i].roomNumber) {
                    rooms[j].isAvailable = false;
                    break;
                }
            }
            reservations[i].status = "CheckedIn";
            repository.saveAll(rooms, reservations);
            return true;
        }
    }
    return false;
}

bool HotelService::checkOutGuest(int reservationId, HotelRepository& repository) {
    for (std::size_t i = 0; i < reservations.size(); ++i) {
        if (reservations[i].id == reservationId && reservations[i].status == "CheckedIn") {
            for (std::size_t j = 0; j < rooms.size(); ++j) {
                if (rooms[j].roomNumber == reservations[i].roomNumber) {
                    rooms[j].isAvailable = true;
                    break;
                }
            }
            reservations[i].status = "CheckedOut";
            repository.saveAll(rooms, reservations);
            return true;
        }
    }
    return false;
}

bool HotelService::cancelReservation(int reservationId, HotelRepository& repository) {
    for (std::size_t i = 0; i < reservations.size(); ++i) {
        if (reservations[i].id == reservationId &&
            reservations[i].status != "CheckedOut" &&
            reservations[i].status != "Canceled") {
            for (std::size_t j = 0; j < rooms.size(); ++j) {
                if (rooms[j].roomNumber == reservations[i].roomNumber) {
                    rooms[j].isAvailable = true;
                    break;
                }
            }
            reservations[i].status = "Canceled";
            repository.saveAll(rooms, reservations);
            return true;
        }
    }
    return false;
}

std::vector<Room> HotelService::getRooms() const {
    return rooms;
}

bool HotelService::roomExists(int roomNumber) const {
    for (std::size_t i = 0; i < rooms.size(); ++i) {
        if (rooms[i].roomNumber == roomNumber) {
            return true;
        }
    }
    return false;
}

bool HotelService::isRoomAvailable(int roomNumber) const {
    for (std::size_t i = 0; i < rooms.size(); ++i) {
        if (rooms[i].roomNumber == roomNumber) {
            return rooms[i].isAvailable;
        }
    }
    return false;
}

bool HotelService::reservationExists(int reservationId) const {
    for (std::size_t i = 0; i < reservations.size(); ++i) {
        if (reservations[i].id == reservationId) {
            return true;
        }
    }
    return false;
}

bool HotelService::validateBookingInput(const std::string& guestName, int roomNumber, const std::string& date) const {
    if (guestName.empty() || roomNumber <= 0 || date.size() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }

    if (!isDigits(date.substr(0, 4)) || !isDigits(date.substr(5, 2)) || !isDigits(date.substr(8, 2))) {
        return false;
    }

    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    return month >= 1 && month <= 12 && day >= 1 && day <= 31;
}
