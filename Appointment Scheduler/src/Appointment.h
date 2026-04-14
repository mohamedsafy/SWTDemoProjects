#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>

class Appointment {
private:
    int id;
    std::string title;
    std::string date;
    std::string time;

public:
    Appointment(int id, std::string title, std::string date, std::string time)
        : id(id), title(title), date(date), time(time) {}

    int getId() { return id; }
    std::string getTitle() { return title; }
    std::string getDate() { return date; }
    std::string getTime() { return time; }

    void setDate(std::string newDate) { date = newDate; }
    void setTime(std::string newTime) { time = newTime; }
};

#endif
