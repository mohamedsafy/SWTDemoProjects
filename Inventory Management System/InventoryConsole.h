#ifndef INVENTORY_CONSOLE_H
#define INVENTORY_CONSOLE_H

#include "InventoryRepository.h"
#include "InventoryService.h"
#include <string>

class InventoryConsole {
public:
    InventoryConsole(InventoryService& service, InventoryRepository& repository);

    void run();
    void showMenu() const;
    void initializeSystem();
    void addProduct();
    void viewInventory() const;
    void updateProductQuantity();
    void searchProduct() const;
    void removeProduct();
    int readInt(const std::string& prompt) const;
    std::string readString(const std::string& prompt) const;

private:
    InventoryService& service;
    InventoryRepository& repository;
};

#endif
