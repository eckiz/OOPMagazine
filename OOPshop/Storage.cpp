#include "Storage.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

static bool isNumber(std::string s) {
    if (s.empty()) return false;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] < '0' || s[i] > '9') return false;
    }
    return true;
}

static bool isDouble(std::string s) {
    if (s.empty()) return false;
    int dotCount = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '.' || s[i] == ',') {
            dotCount++;
            if (dotCount > 1) return false;
        }
        else if (s[i] < '0' || s[i] > '9') return false;
    }
    return true;
}

static void fixComma(std::string& s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ',') s[i] = '.';
    }
}


void Storage::CreateStorage() {
    products.push_back(Product(1, "iPhone 15", 999.99, 10));
    products.push_back(Product(2, "Samsung S24", 899.99, 15));
}


void Storage::ShowStorage(int mode) {
    std::cout << "\n--- СКЛАД ТОВАРОВ ---\n";
    if (products.empty()) {
        std::cout << "Склад пуст.\n";
        return;
    }
    for (int i = 0; i < products.size(); i++) {
        std::cout << "[" << products[i].getId() << "] " << products[i].getName()
            << " | Цена: " << products[i].getPrice() << " руб. | Остаток: " << products[i].getCount() << " шт.\n";
    }
}


void Storage::AddStorageItem(const Product& p) {
    products.push_back(p);
}


void Storage::RemoveStorageItem(unsigned int id) {
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->getId() == id) {
            products.erase(it);
            std::cout << "Товар удален из базы.\n";
            return;
        }
    }
    std::cout << "Ошибка: Товар с ID " << id << " не найден.\n";
}


void Storage::AddNewItem() {
    std::string name, temp;
    double price = 0;
    unsigned int count = 0;

    std::cout << "Название товара: ";
    std::getline(std::cin, name);

    while (true) {
        std::cout << "Введите цену: ";
        std::getline(std::cin, temp);
        if (isDouble(temp)) {
            fixComma(temp);
            price = std::stod(temp);
            break;
        }
        std::cout << "[ОШИБКА] Введите число!\n";
    }

    while (true) {
        std::cout << "Количество: ";
        std::getline(std::cin, temp);
        if (isNumber(temp)) {
            count = std::stoul(temp);
            break;
        }
        std::cout << "[ОШИБКА] Введите целое число!\n";
    }

    unsigned int newId = products.empty() ? 1 : products.back().getId() + 1;
    products.push_back(Product(newId, name, price, count));
    std::cout << "[УСПЕХ] Товар добавлен.\n";
    SaveToFile();
}

void Storage::DeleteItem() {
    std::string temp;
    std::cout << "Введите ID товара для удаления: ";
    std::getline(std::cin, temp);
    if (isNumber(temp)) {
        RemoveStorageItem(std::stoul(temp));
        SaveToFile();
    }
    else {
        std::cout << "[ОШИБКА] Введите числовой ID!\n";
    }
}

void Storage::ChangePrice() {
    std::string temp;
    std::cout << "ID товара: ";
    std::getline(std::cin, temp);
    if (!isNumber(temp)) return;

    unsigned int id = std::stoul(temp);
    for (int i = 0; i < products.size(); i++) {
        if (products[i].getId() == id) {
            while (true) {
                std::cout << "Новая цена: ";
                std::getline(std::cin, temp);
                if (isDouble(temp)) {
                    fixComma(temp);
                    products[i].setPrice(std::stod(temp));
                    SaveToFile();
                    return;
                }
            }
        }
    }
}

void Storage::ChangeName() {
    std::string temp, newName;
    std::cout << "ID товара: ";
    std::getline(std::cin, temp);
    if (!isNumber(temp)) return;

    unsigned int id = std::stoul(temp);
    for (int i = 0; i < products.size(); i++) {
        if (products[i].getId() == id) {
            std::cout << "Новое название: ";
            std::getline(std::cin, newName);
            products[i].setName(newName);
            SaveToFile();
            return;
        }
    }
}

std::vector<Product>& Storage::getProducts() { return products; }

void Storage::SaveToFile() {
    std::ofstream out("products.txt");
    if (out.is_open()) {
        for (int i = 0; i < products.size(); i++) {
            out << products[i].getId() << ";"
                << products[i].getName() << ";"
                << products[i].getPrice() << ";"
                << products[i].getCount() << "\n";
        }
    }
    out.close();
}

void Storage::LoadFromFile() {
    std::ifstream in("products.txt");
    if (!in.is_open()) return;
    products.clear();
    std::string line;
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string item, name;
        unsigned int id, count;
        double price;
        std::getline(ss, item, ';'); id = std::stoul(item);
        std::getline(ss, name, ';');
        std::getline(ss, item, ';'); price = std::stod(item);
        std::getline(ss, item, ';'); count = std::stoul(item);
        products.push_back(Product(id, name, price, count));
    }
    in.close();
}