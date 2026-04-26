#include "HotelConsole.h"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

namespace {
bool parseInt(const std::string& text, int& value) {
    std::istringstream input(text);
    input >> value;
    return !input.fail() && input.eof();
}
}

HotelConsole::HotelConsole(HotelService& hotelService) : service(hotelService) {}

void HotelConsole::showMenu() const {
    std::cout << "\n--- Hotel Management System ---\n";
    std::cout << "1. Book Room\n";
    std::cout << "2. Check-in Guest\n";
    std::cout << "3. Check-out Guest\n";
    std::cout << "4. Cancel Reservation\n";
    std::cout << "5. View Room Availability\n";
    std::cout << "6. Exit\n";
}

void HotelConsole::bookRoom() {
    HotelRepository repository;
    std::string guestName = readString("Enter guest name: ");
    int roomNumber = readInt("Enter room number: ");
    std::string date = readString("Enter booking date (YYYY-MM-DD): ");

    try {
        Reservation reservation = service.bookRoom(guestName, roomNumber, date, repository);
        std::cout << "Room booked successfully. Reservation ID: " << reservation.id << ".\n";
    } catch (const std::exception& error) {
        std::cout << error.what() << "\n";
    }
}

void HotelConsole::checkInGuest() {
    HotelRepository repository;
    int reservationId = readInt("Enter reservation ID: ");

    if (service.checkInGuest(reservationId, repository)) {
        std::cout << "Guest checked in successfully.\n";
    } else {
        std::cout << "Check-in failed. Reservation ID is invalid or not booked.\n";
    }
}

void HotelConsole::checkOutGuest() {
    HotelRepository repository;
    int reservationId = readInt("Enter reservation ID: ");

    if (service.checkOutGuest(reservationId, repository)) {
        std::cout << "Guest checked out successfully.\n";
    } else {
        std::cout << "Check-out failed. Reservation ID is invalid or not checked in.\n";
    }
}

void HotelConsole::cancelReservation() {
    HotelRepository repository;
    int reservationId = readInt("Enter reservation ID: ");

    if (service.cancelReservation(reservationId, repository)) {
        std::cout << "Reservation canceled successfully.\n";
    } else {
        std::cout << "Cancellation failed. Reservation ID is invalid or already finalized.\n";
    }
}

void HotelConsole::viewRoomAvailability() {
    std::vector<Room> rooms = service.getRooms();
    if (rooms.empty()) {
        std::cout << "No rooms available in the system.\n";
        return;
    }

    for (std::size_t i = 0; i < rooms.size(); ++i) {
        std::cout << "Room " << rooms[i].roomNumber << ": "
                  << (rooms[i].isAvailable ? "Available" : "Unavailable") << "\n";
    }
}

int HotelConsole::readInt(const std::string& prompt) const {
    for (;;) {
        std::cout << prompt;
        std::string line;
        if (!std::getline(std::cin, line)) {
            return 0;
        }

        int value = 0;
        if (parseInt(line, value)) {
            return value;
        }
        std::cout << "Invalid number. Try again.\n";
    }
}

std::string HotelConsole::readString(const std::string& prompt) const {
    std::cout << prompt;
    std::string value;
    std::getline(std::cin, value);
    return value;
}

void HotelConsole::run() {
    HotelRepository repository;
    service.initialize(repository);

    for (;;) {
        showMenu();
        int choice = readInt("Select option: ");

        if (choice == 1) {
            bookRoom();
        } else if (choice == 2) {
            checkInGuest();
        } else if (choice == 3) {
            checkOutGuest();
        } else if (choice == 4) {
            cancelReservation();
        } else if (choice == 5) {
            viewRoomAvailability();
        } else if (choice == 6) {
            std::cout << "Goodbye.\n";
            break;
        } else {
            std::cout << "Invalid choice. Enter 1-6.\n";
        }
    }
}
