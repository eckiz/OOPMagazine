#include "Storage.hpp"
#include <iostream>

void Storage::CreateStorage() {
    products.push_back(Product(1, "iPhone 15", 999.99, 10));
    products.push_back(Product(2, "Samsung S24", 899.99, 15));
}

void Storage::ShowStorage(int mode) {
    std::cout << "\n--- СКЛАД ТОВАРОВ ---\n";
    if (products.empty()) std::cout << "Склад пуст.\n";
    for (const auto& p : products) {
        std::cout << "[" << p.getId() << "] " << p.getName()
            << " | Цена: " << p.getPrice() << " руб. | Остаток: " << p.getCount() << " шт.\n";
    }
}

void Storage::AddStorageItem(const Product& p) { products.push_back(p); }

void Storage::RemoveStorageItem(unsigned int id) {
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->getId() == id) {
            products.erase(it);
            std::cout << "Товар удален.\n";
            return;
        }
    }
    std::cout << "Ошибка: Товар с ID " << id << " не найден.\n";
}

void Storage::AddNewItem() {
    std::string n;
    double p;
    unsigned int c;

    while (std::cin.get() != '\n');

    std::cout << "Название товара: ";
    std::getline(std::cin, n);

    std::cout << "Цена: ";
    while (!(std::cin >> p)) {
        std::cout << "Ошибка! Введите число: ";
        std::cin.clear();
        while (std::cin.get() != '\n'); 
    }

    std::cout << "Количество: ";
    while (!(std::cin >> c)) {
        std::cout << "Ошибка! Введите целое число: ";
        std::cin.clear();
        while (std::cin.get() != '\n');
    }

    unsigned int newId = products.empty() ? 1 : products.back().getId() + 1;
    products.push_back(Product(newId, n, p, c));
    std::cout << "[УСПЕХ] Товар добавлен.\n";
}

void Storage::DeleteItem() {
    unsigned int id;
    std::cout << "Введите ID товара для удаления: "; std::cin >> id;
    RemoveStorageItem(id);
}

void Storage::ChangePrice() {
    unsigned int id; double p;
    std::cout << "ID товара: "; std::cin >> id;
    for (auto& item : products) {
        if (item.getId() == id) {
            std::cout << "Новая цена: "; std::cin >> p;
            item.setPrice(p);
            return;
        }
    }
    std::cout << "Товар не найден.\n";
}

void Storage::ChangeName() {
    unsigned int id; std::string n;
    std::cout << "ID товара: "; std::cin >> id;
    for (auto& item : products) {
        if (item.getId() == id) {
            std::cout << "Новое название: "; std::cin >> n;
            item.setName(n);
            return;
        }
    }
    std::cout << "Товар не найден.\n";
}

std::vector<Product>& Storage::getProducts() { return products; }