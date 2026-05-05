#include "Sale.hpp"
#include "Storage.hpp"
#include <iostream>

Sale::Sale() : cash(0), cashIncome(0), cashIncmone(0) {}

void Sale::Selling(Storage* storage) {
    unsigned int id;
    std::cout << "Введите ID телефона для продажи: "; std::cin >> id;

    // 1. Поиск товара в storage->getProducts()
    // 2. Если найден — уменьшаем count
    // 3. Добавляем в check.CheckPushBack()
    // 4. Увеличиваем cashIncome

    std::cout << "Продажа оформлена!" << std::endl;
    check.PrintCheck(1000.0); // Пример
}

void Sale::ShowIncome() const {
    std::cout << "Общая выручка: " << cashIncome << std::endl;
}

double Sale::getCash() const { return cash; }
void Sale::setCash(double c) { cash = c; }