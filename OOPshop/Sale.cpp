#include "Sale.hpp"
#include <iostream>

Sale::Sale() : cash(0), cashIncome(0), cashlessIncome(0) {}

void Sale::SetCash(double amount) { cash = amount; }
double Sale::getCash() const { return cash; }

void Sale::Selling(Storage& storage) {
    storage.ShowStorage(0);
    std::vector<Product>& prods = storage.getProducts();
    double totalSum = 0;

    while (true) {
        unsigned int id, count;
        std::cout << "\nВведите ID товара (0 для завершения чека): "; std::cin >> id;
        if (id == 0) break;

        bool found = false;
        for (auto& p : prods) {
            if (p.getId() == id) {
                found = true;
                std::cout << "Количество (макс " << p.getCount() << "): "; std::cin >> count;
                if (count > 0 && count <= p.getCount()) {
                    p.setCount(p.getCount() - count);
                    check.CheckPushBack(Product(p.getId(), p.getName(), p.getPrice(), count));
                    totalSum += p.getPrice() * count;
                    std::cout << "Добавлено в чек.\n";
                }
                else {
                    std::cout << "Ошибка: Неверное количество!\n";
                }
                break;
            }
        }
        if (!found) std::cout << "Товар не найден!\n";
    }

    if (totalSum > 0) {
        int payType;
        std::cout << "\nСумма: " << totalSum << " руб.\n1 - Наличные\n2 - Карта\nОплата: ";
        std::cin >> payType;

        if (payType == 1) cashIncome += totalSum;
        else cashlessIncome += totalSum;

        check.PrintCheck(totalSum);
    }
}

void Sale::ShowIncome() const {
    std::cout << "\n--- СТАТИСТИКА ДОХОДОВ ---\n";
    std::cout << "Наличные: " << cashIncome << " руб.\n";
    std::cout << "Безнал: " << cashlessIncome << " руб.\n";
    std::cout << "Общая выручка: " << (cashIncome + cashlessIncome) << " руб.\n";
}

void Sale::StorageReturner(Storage& storage) {
    std::cout << "Модуль возврата товара в разработке...\n";
}