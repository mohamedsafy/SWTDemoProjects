#include "HotelRepository.h"

#include <fstream>

#include "json.hpp"

using nlohmann::json;

namespace {
json loadRoot(const std::string& filePath) {
    std::ifstream input(filePath.c_str());
    if (!input) {
        return json();
    }

    try {
        json root;
        input >> root;
        return root;
    } catch (...) {
        return json();
    }
}
}

HotelRepository::HotelRepository(const std::string& path) : filePath(path) {}

std::vector<Room> HotelRepository::loadRooms() const {
    std::vector<Room> rooms;
    json root = loadRoot(filePath);
    if (!root.is_object() || !root.contains("rooms") || !root["rooms"].is_array()) {
        return rooms;
    }

    for (std::size_t i = 0; i < root["rooms"].size(); ++i) {
        const json& item = root["rooms"][i];
        if (item.contains("roomNumber") && item.contains("isAvailable")) {
            rooms.push_back(Room(item["roomNumber"].get<int>(), item["isAvailable"].get<bool>()));
        }
    }
    return rooms;
}

std::vector<Reservation> HotelRepository::loadReservations() const {
    std::vector<Reservation> reservations;
    json root = loadRoot(filePath);
    if (!root.is_object() || !root.contains("reservations") || !root["reservations"].is_array()) {
        return reservations;
    }

    for (std::size_t i = 0; i < root["reservations"].size(); ++i) {
        const json& item = root["reservations"][i];
        if (item.contains("id") && item.contains("guestName") && item.contains("roomNumber") &&
            item.contains("date") && item.contains("status")) {
            reservations.push_back(Reservation(
                item["id"].get<int>(),
                item["guestName"].get<std::string>(),
                item["roomNumber"].get<int>(),
                item["date"].get<std::string>(),
                item["status"].get<std::string>()));
        }
    }
    return reservations;
}

void HotelRepository::saveAll(const std::vector<Room>& rooms, const std::vector<Reservation>& reservations) const {
    json root;
    root["rooms"] = json::array();
    root["reservations"] = json::array();

    for (std::size_t i = 0; i < rooms.size(); ++i) {
        json item;
        item["roomNumber"] = rooms[i].roomNumber;
        item["isAvailable"] = rooms[i].isAvailable;
        root["rooms"].push_back(item);
    }

    for (std::size_t i = 0; i < reservations.size(); ++i) {
        json item;
        item["id"] = reservations[i].id;
        item["guestName"] = reservations[i].guestName;
        item["roomNumber"] = reservations[i].roomNumber;
        item["date"] = reservations[i].date;
        item["status"] = reservations[i].status;
        root["reservations"].push_back(item);
    }

    std::ofstream output(filePath.c_str(), std::ios::trunc);
    output << root.dump(2);
}

bool HotelRepository::fileExists() const {
    std::ifstream input(filePath.c_str());
    return input.good();
}
