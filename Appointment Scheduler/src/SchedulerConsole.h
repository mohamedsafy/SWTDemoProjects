#ifndef SCHEDULER_CONSOLE_H
#define SCHEDULER_CONSOLE_H

#include "SchedulerService.h"

class SchedulerConsole {
private:
    SchedulerService service;

public:
    SchedulerConsole(SchedulerService service);
    void run();
    void showMenu();
    void handleBook();
    void handleView();
    void handleReschedule();
    void handleCancel();
    void handleAvailability();
};

#endif
