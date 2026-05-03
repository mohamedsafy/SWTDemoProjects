#include "InventoryConsole.h"
#include "Utils.h"
#include <iostream>
#include <sstream>
#include <vector>

namespace {
void printProducts(const std::vector<Product>& products) {
    for (size_t i = 0; i < products.size(); ++i) {
        std::cout << "ID: " << products[i].id
                  << " | Name: " << products[i].name
                  << " | Quantity: " << products[i].quantity << "\n";
    }
}
}

InventoryConsole::InventoryConsole(InventoryService& serviceRef, InventoryRepository& repositoryRef)
    : service(serviceRef), repository(repositoryRef) {}

void InventoryConsole::run() {
    initializeSystem();

    while (true) {
        showMenu();
        int choice = readInt("Select option: ");

        if (choice == 1) {
            addProduct();
        } else if (choice == 2) {
            viewInventory();
        } else if (choice == 3) {
            updateProductQuantity();
        } else if (choice == 4) {
            searchProduct();
        } else if (choice == 5) {
            removeProduct();
        } else if (choice == 6) {
            std::cout << "Exiting application.\n";
            break;
        } else {
            std::cout << "Invalid choice. Enter a number from 1 to 6.\n";
        }
    }
}

void InventoryConsole::showMenu() const {
    std::cout << "\n--- Inventory Management System ---\n";
    std::cout << "1. Add Product\n";
    std::cout << "2. View Inventory\n";
    std::cout << "3. Update Product Quantity\n";
    std::cout << "4. Search Product\n";
    std::cout << "5. Remove Product\n";
    std::cout << "6. Exit\n";
}

void InventoryConsole::initializeSystem() {
    service.initialize(repository.loadProducts());
    std::cout << "Inventory loaded from "
              << (repository.fileExists() ? "existing" : "new")
              << " storage.\n";
}

void InventoryConsole::addProduct() {
    std::string name = readString("Enter product name: ");
    int quantity = readInt("Enter product quantity: ");

    Product created = service.addProduct(name, quantity);
    if (created.id == 0) {
        std::cout << "Invalid product data. Name must not be empty and quantity cannot be negative.\n";
        return;
    }

    repository.saveProducts(service.getAllProducts());
    std::cout << "Product added successfully with ID " << created.id << ".\n";
}

void InventoryConsole::viewInventory() const {
    std::vector<Product> products = service.getAllProducts();
    if (products.empty()) {
        std::cout << "Inventory is empty.\n";
        return;
    }

    printProducts(products);
}

void InventoryConsole::updateProductQuantity() {
    int productId = readInt("Enter product ID: ");
    int newQuantity = readInt("Enter new quantity: ");

    if (!service.updateProductQuantity(productId, newQuantity)) {
        std::cout << "Unable to update product. Check the ID and quantity.\n";
        return;
    }

    repository.saveProducts(service.getAllProducts());
    std::cout << "Product quantity updated successfully.\n";
}

void InventoryConsole::searchProduct() const {
    std::string query = readString("Enter product name or part of name: ");
    if (!Utils::isNonEmptyText(query)) {
        std::cout << "Search text cannot be empty.\n";
        return;
    }

    std::vector<Product> matches = service.searchProducts(query);
    if (matches.empty()) {
        std::cout << "No matching products found.\n";
        return;
    }

    printProducts(matches);
}

void InventoryConsole::removeProduct() {
    int productId = readInt("Enter product ID to remove: ");
    if (!service.removeProduct(productId)) {
        std::cout << "Unable to remove product. Check the product ID.\n";
        return;
    }

    repository.saveProducts(service.getAllProducts());
    std::cout << "Product removed successfully.\n";
}

int InventoryConsole::readInt(const std::string& prompt) const {
    while (true) {
        std::cout << prompt;
        std::string line;
        if (!std::getline(std::cin, line)) {
            return 0;
        }

        std::istringstream stream(line);
        int value = 0;
        if (stream >> value && stream.eof()) {
            return value;
        }

        std::cout << "Invalid number. Please try again.\n";
    }
}

std::string InventoryConsole::readString(const std::string& prompt) const {
    std::cout << prompt;
    std::string value;
    std::getline(std::cin, value);
    return value;
}
