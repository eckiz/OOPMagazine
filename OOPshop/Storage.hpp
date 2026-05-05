#ifndef STORAGE_HPP
#define STORAGE_HPP

#include <vector>
#include "Product.hpp"

class Storage {
private:
    std::vector<Product> products;

public:
    void AddNewItem();
    void DeleteItem();
    void ShowStorage(int mode = 0);
    void ChengePrice();
    void ChengeName();
    // Геттер для получения списка (для Sale)
    std::vector<Product>& getProducts();
};

#endif