#pragma once
#include <vector>
#include "Product.hpp"

class Storage {
private:
    std::vector<Product> products;
public:
    void CreateStorage();
    void ShowStorage(int mode);
    void AddStorageItem(const Product& p);
    void RemoveStorageItem(unsigned int id);
    void ChangePrice();
    void ChangeName();
    void AddNewItem();
    void DeleteItem();
    std::vector<Product>& getProducts();
};