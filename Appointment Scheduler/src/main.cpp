#include "AppointmentRepository.h"
#include "SchedulerConsole.h"
#include "SchedulerService.h"

int main() {
    AppointmentRepository repo("appointments.json");
    SchedulerService service(repo);
    SchedulerConsole console(service);
    console.run();
    return 0;
}
