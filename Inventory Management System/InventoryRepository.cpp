#include "InventoryRepository.h"
#include "json.hpp"
#include <fstream>

using json = nlohmann::json;

InventoryRepository::InventoryRepository(const std::string& path) : filePath(path) {}

std::vector<Product> InventoryRepository::loadProducts() const {
    std::vector<Product> products;
    std::ifstream input(filePath.c_str());
    if (!input) {
        return products;
    }

    try {
        json data;
        input >> data;
        if (!data.contains("products") || !data["products"].is_array()) {
            return products;
        }

        for (size_t i = 0; i < data["products"].size(); ++i) {
            const json& item = data["products"][i];
            if (!item.contains("id") || !item.contains("name") || !item.contains("quantity")) {
                continue;
            }

            Product product;
            product.id = item["id"].get<int>();
            product.name = item["name"].get<std::string>();
            product.quantity = item["quantity"].get<int>();
            products.push_back(product);
        }
    } catch (...) {
        products.clear();
    }

    return products;
}

void InventoryRepository::saveProducts(const std::vector<Product>& products) const {
    json data;
    data["products"] = json::array();

    for (size_t i = 0; i < products.size(); ++i) {
        json item;
        item["id"] = products[i].id;
        item["name"] = products[i].name;
        item["quantity"] = products[i].quantity;
        data["products"].push_back(item);
    }

    std::ofstream output(filePath.c_str());
    output << data.dump(2);
}

bool InventoryRepository::fileExists() const {
    std::ifstream input(filePath.c_str());
    return input.good();
}
