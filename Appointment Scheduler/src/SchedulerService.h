#ifndef SCHEDULER_SERVICE_H
#define SCHEDULER_SERVICE_H

#include <vector>

#include "AppointmentRepository.h"

class SchedulerService {
private:
    AppointmentRepository& repo;

public:
    SchedulerService(AppointmentRepository& repo);
    void initialize();
    bool bookAppointment(std::string title, std::string date, std::string time);
    std::vector<Appointment> viewAppointments();
    bool reschedule(int id, std::string date, std::string time);
    bool cancel(int id);
    bool isAvailable(std::string date, std::string time);
    int generateId();
};

#endif
