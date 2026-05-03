#ifndef INVENTORY_SERVICE_H
#define INVENTORY_SERVICE_H

#include "Product.h"
#include <string>
#include <vector>

class InventoryService {
public:
    InventoryService();

    void initialize(const std::vector<Product>& loadedProducts);
    std::vector<Product> getAllProducts() const;
    Product addProduct(const std::string& name, int quantity);
    bool updateProductQuantity(int productId, int newQuantity);
    std::vector<Product> searchProducts(const std::string& nameQuery) const;
    bool removeProduct(int productId);
    bool productExists(int productId) const;
    bool validateProductInput(const std::string& name, int quantity) const;

private:
    int generateNextProductId();
    void recalculateNextProductId();

    std::vector<Product> products;
    int nextProductId;
};

#endif
