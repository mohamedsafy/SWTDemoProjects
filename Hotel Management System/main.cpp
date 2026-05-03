#include "HotelConsole.h"
#include "HotelService.h"

int main() {
    HotelService service;
    HotelConsole console(service);
    console.run();
    return 0;
}
