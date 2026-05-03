#ifndef INVENTORY_REPOSITORY_H
#define INVENTORY_REPOSITORY_H

#include "Product.h"
#include <string>
#include <vector>

class InventoryRepository {
public:
    explicit InventoryRepository(const std::string& filePath = "inventory.json");

    std::vector<Product> loadProducts() const;
    void saveProducts(const std::vector<Product>& products) const;
    bool fileExists() const;

private:
    std::string filePath;
};

#endif
