#include "SchedulerConsole.h"

#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "Appointment.h"
#include "Utils.h"

SchedulerConsole::SchedulerConsole(SchedulerService service) : service(service) {}

void SchedulerConsole::showMenu() {
    std::cout << "\n==== Appointment Scheduler ====\n";
    std::cout << "1. Book Appointment\n";
    std::cout << "2. View Appointments\n";
    std::cout << "3. Reschedule Appointment\n";
    std::cout << "4. Cancel Appointment\n";
    std::cout << "5. Check Availability\n";
    std::cout << "6. Exit\n";
    std::cout << "Choose an option: ";
}

void SchedulerConsole::run() {
    service.initialize();

    int choice = 0;
    while (true) {
        showMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid option.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 1) {
            handleBook();
        } else if (choice == 2) {
            handleView();
        } else if (choice == 3) {
            handleReschedule();
        } else if (choice == 4) {
            handleCancel();
        } else if (choice == 5) {
            handleAvailability();
        } else if (choice == 6) {
            std::cout << "Goodbye.\n";
            break;
        } else {
            std::cout << "Invalid option.\n";
        }
    }
}

void SchedulerConsole::handleBook() {
    std::string title;
    std::string date;
    std::string time;

    std::cout << "Title: ";
    std::getline(std::cin, title);
    std::cout << "Date (YYYY-MM-DD): ";
    std::getline(std::cin, date);
    std::cout << "Time (HH:MM): ";
    std::getline(std::cin, time);

    if (service.bookAppointment(title, date, time)) {
        std::cout << "Appointment booked successfully.\n";
    } else {
        std::cout << "Failed to book appointment (invalid input or slot unavailable).\n";
    }
}

void SchedulerConsole::handleView() {
    std::vector<Appointment> appointments = service.viewAppointments();
    if (appointments.empty()) {
        std::cout << "No appointments found.\n";
        return;
    }

    std::cout << "\nAppointments:\n";
    for (std::size_t i = 0; i < appointments.size(); ++i) {
        std::cout << "ID: " << appointments[i].getId()
                  << ", Title: " << appointments[i].getTitle()
                  << ", Date: " << appointments[i].getDate()
                  << ", Time: " << appointments[i].getTime() << "\n";
    }
}

void SchedulerConsole::handleReschedule() {
    int id = 0;
    std::string date;
    std::string time;

    std::cout << "Appointment ID: ";
    if (!(std::cin >> id)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid ID.\n";
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "New Date (YYYY-MM-DD): ";
    std::getline(std::cin, date);
    std::cout << "New Time (HH:MM): ";
    std::getline(std::cin, time);

    if (service.reschedule(id, date, time)) {
        std::cout << "Appointment rescheduled successfully.\n";
    } else {
        std::cout << "Failed to reschedule appointment.\n";
    }
}

void SchedulerConsole::handleCancel() {
    int id = 0;
    std::cout << "Appointment ID: ";
    if (!(std::cin >> id)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid ID.\n";
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (service.cancel(id)) {
        std::cout << "Appointment canceled successfully.\n";
    } else {
        std::cout << "Failed to cancel appointment (invalid ID).\n";
    }
}

void SchedulerConsole::handleAvailability() {
    std::string date;
    std::string time;

    std::cout << "Date (YYYY-MM-DD): ";
    std::getline(std::cin, date);
    std::cout << "Time (HH:MM): ";
    std::getline(std::cin, time);

    if (!Utils::isValidDate(date) || !Utils::isValidTime(time)) {
        std::cout << "Invalid date or time format.\n";
        return;
    }

    if (service.isAvailable(date, time)) {
        std::cout << "Slot is available.\n";
    } else {
        std::cout << "Slot is not available.\n";
    }
}
