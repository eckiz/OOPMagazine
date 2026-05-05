#include "Storage.hpp"
#include <iostream>

void Storage::ShowStorage(int mode) {
    std::cout << "\n--- Склад телефонов ---" << std::endl;
    for (const auto& p : products) {
        std::cout << "ID: " << p.getID() << " | " << p.getName()
            << " | Цена: " << p.getPrice() << " | Кол-во: " << p.getCount() << std::endl;
    }
}

void Storage::AddNewItem() {
    std::string name; double price; unsigned int count;
    std::cout << "Название телефона: "; std::cin >> name;
    std::cout << "Цена: "; std::cin >> price;
    std::cout << "Количество: "; std::cin >> count;

    products.push_back(Product(products.size() + 1, name, price, count));
}

void Storage::ChengePrice() {
    unsigned int id; double newPrice;
    std::cout << "ID товара: "; std::cin >> id;
    std::cout << "Новая цена: "; std::cin >> newPrice;
    // Логика поиска и обновления
}

std::vector<Product>& Storage::getProducts() { return products; }