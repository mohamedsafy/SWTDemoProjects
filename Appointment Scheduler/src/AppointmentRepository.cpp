#include "AppointmentRepository.h"

#include <fstream>

#include "json.hpp"

using nlohmann::json;

AppointmentRepository::AppointmentRepository(std::string filePath) : filePath(filePath) {}

void AppointmentRepository::load() {
    appointments.clear();

    std::ifstream in(filePath.c_str());
    if (!in.is_open()) {
        return;
    }

    json root;
    try {
        in >> root;
    } catch (...) {
        return;
    }

    if (!root.is_object() || !root.contains("appointments") || !root["appointments"].is_array()) {
        return;
    }

    const json& items = root["appointments"];
    for (json::const_iterator it = items.begin(); it != items.end(); ++it) {
        if (!it->is_object()) {
            continue;
        }
        if (!it->contains("id") || !it->contains("title") || !it->contains("date") || !it->contains("time")) {
            continue;
        }
        appointments.push_back(
            Appointment(
                (*it)["id"].get<int>(),
                (*it)["title"].get<std::string>(),
                (*it)["date"].get<std::string>(),
                (*it)["time"].get<std::string>()
            )
        );
    }
}

void AppointmentRepository::save() {
    json root;
    root["appointments"] = json::array();

    for (std::size_t i = 0; i < appointments.size(); ++i) {
        json item;
        item["id"] = appointments[i].getId();
        item["title"] = appointments[i].getTitle();
        item["date"] = appointments[i].getDate();
        item["time"] = appointments[i].getTime();
        root["appointments"].push_back(item);
    }

    std::ofstream out(filePath.c_str(), std::ios::trunc);
    out << root.dump(2);
}

std::vector<Appointment> AppointmentRepository::getAll() {
    return appointments;
}

void AppointmentRepository::add(Appointment appointment) {
    appointments.push_back(appointment);
}

bool AppointmentRepository::remove(int id) {
    for (std::size_t i = 0; i < appointments.size(); ++i) {
        if (appointments[i].getId() == id) {
            appointments.erase(appointments.begin() + static_cast<std::vector<Appointment>::difference_type>(i));
            return true;
        }
    }
    return false;
}

bool AppointmentRepository::update(Appointment appointment) {
    for (std::size_t i = 0; i < appointments.size(); ++i) {
        if (appointments[i].getId() == appointment.getId()) {
            appointments[i] = appointment;
            return true;
        }
    }
    return false;
}
