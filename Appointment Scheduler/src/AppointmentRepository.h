#ifndef APPOINTMENT_REPOSITORY_H
#define APPOINTMENT_REPOSITORY_H

#include <string>
#include <vector>

#include "Appointment.h"

class AppointmentRepository {
private:
    std::vector<Appointment> appointments;
    std::string filePath;

public:
    AppointmentRepository(std::string filePath);
    void load();
    void save();
    std::vector<Appointment> getAll();
    void add(Appointment appointment);
    bool remove(int id);
    bool update(Appointment appointment);
};

#endif
