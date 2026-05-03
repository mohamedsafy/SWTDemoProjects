#include "InventoryService.h"
#include "Utils.h"
#include <cstddef>

InventoryService::InventoryService() : nextProductId(1) {}

void InventoryService::initialize(const std::vector<Product>& loadedProducts) {
    products = loadedProducts;
    recalculateNextProductId();
}

std::vector<Product> InventoryService::getAllProducts() const {
    return products;
}

Product InventoryService::addProduct(const std::string& name, int quantity) {
    if (!validateProductInput(name, quantity)) {
        return Product{0, "", -1};
    }

    Product product = {generateNextProductId(), name, quantity};
    products.push_back(product);
    return product;
}

bool InventoryService::updateProductQuantity(int productId, int newQuantity) {
    if (!Utils::isPositiveId(productId) || !Utils::isNonNegativeQuantity(newQuantity)) {
        return false;
    }

    for (size_t i = 0; i < products.size(); ++i) {
        if (products[i].id == productId) {
            products[i].quantity = newQuantity;
            return true;
        }
    }

    return false;
}

std::vector<Product> InventoryService::searchProducts(const std::string& nameQuery) const {
    std::vector<Product> matches;
    if (!Utils::isNonEmptyText(nameQuery)) {
        return matches;
    }

    for (size_t i = 0; i < products.size(); ++i) {
        if (Utils::containsIgnoreCase(products[i].name, nameQuery)) {
            matches.push_back(products[i]);
        }
    }

    return matches;
}

bool InventoryService::removeProduct(int productId) {
    if (!Utils::isPositiveId(productId)) {
        return false;
    }

    for (size_t i = 0; i < products.size(); ++i) {
        if (products[i].id == productId) {
            products.erase(products.begin() + static_cast<std::ptrdiff_t>(i));
            return true;
        }
    }

    return false;
}

bool InventoryService::productExists(int productId) const {
    if (!Utils::isPositiveId(productId)) {
        return false;
    }

    for (size_t i = 0; i < products.size(); ++i) {
        if (products[i].id == productId) {
            return true;
        }
    }

    return false;
}

bool InventoryService::validateProductInput(const std::string& name, int quantity) const {
    return Utils::isNonEmptyText(name) && Utils::isNonNegativeQuantity(quantity);
}

int InventoryService::generateNextProductId() {
    return nextProductId++;
}

void InventoryService::recalculateNextProductId() {
    nextProductId = 1;
    for (size_t i = 0; i < products.size(); ++i) {
        if (products[i].id >= nextProductId) {
            nextProductId = products[i].id + 1;
        }
    }
}
