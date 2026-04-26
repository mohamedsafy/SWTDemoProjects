#include "InventoryConsole.h"

int main() {
    InventoryRepository repository;
    InventoryService service;
    InventoryConsole console(service, repository);
    console.run();
    return 0;
}
