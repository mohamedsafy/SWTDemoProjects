#include "SchedulerService.h"

#include "Utils.h"

SchedulerService::SchedulerService(AppointmentRepository& repo) : repo(repo) {}

void SchedulerService::initialize() {
    repo.load();
}

bool SchedulerService::bookAppointment(std::string title, std::string date, std::string time) {
    if (!Utils::isValidDate(date) || !Utils::isValidTime(time)) {
        return false;
    }

    std::vector<Appointment> all = repo.getAll();
    for (std::size_t i = 0; i < all.size(); ++i) {
        if (all[i].getDate() == date && all[i].getTime() == time) {
            return false;
        }
    }

    Appointment appointment(generateId(), title, date, time);
    repo.add(appointment);
    repo.save();
    return true;
}

std::vector<Appointment> SchedulerService::viewAppointments() {
    return repo.getAll();
}

bool SchedulerService::reschedule(int id, std::string date, std::string time) {
    if (!Utils::isValidDate(date) || !Utils::isValidTime(time)) {
        return false;
    }

    std::vector<Appointment> all = repo.getAll();
    int targetIndex = -1;
    for (std::size_t i = 0; i < all.size(); ++i) {
        if (all[i].getId() == id) {
            targetIndex = static_cast<int>(i);
        } else if (all[i].getDate() == date && all[i].getTime() == time) {
            return false;
        }
    }

    if (targetIndex < 0) {
        return false;
    }

    all[static_cast<std::size_t>(targetIndex)].setDate(date);
    all[static_cast<std::size_t>(targetIndex)].setTime(time);

    if (!repo.update(all[static_cast<std::size_t>(targetIndex)])) {
        return false;
    }
    repo.save();
    return true;
}

bool SchedulerService::cancel(int id) {
    if (!repo.remove(id)) {
        return false;
    }
    repo.save();
    return true;
}

bool SchedulerService::isAvailable(std::string date, std::string time) {
    if (!Utils::isValidDate(date) || !Utils::isValidTime(time)) {
        return false;
    }

    std::vector<Appointment> all = repo.getAll();
    for (std::size_t i = 0; i < all.size(); ++i) {
        if (all[i].getDate() == date && all[i].getTime() == time) {
            return false;
        }
    }
    return true;
}

int SchedulerService::generateId() {
    std::vector<Appointment> all = repo.getAll();
    int maxId = 0;
    for (std::size_t i = 0; i < all.size(); ++i) {
        if (all[i].getId() > maxId) {
            maxId = all[i].getId();
        }
    }
    return maxId + 1;
}
