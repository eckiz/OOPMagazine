#ifndef STORAGE_HPP
#define STORAGE_HPP
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
    void SaveToFile();
    void LoadFromFile();
    std::vector<Product>& getProducts();
};
#endif