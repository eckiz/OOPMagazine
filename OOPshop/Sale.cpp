#include "Sale.hpp"
#include <iostream>
#include <string>

static bool isNumberSale(std::string s) {
    if (s.empty()) return false;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] < '0' || s[i] > '9') return false;
    }
    return true;
}

Sale::Sale() : cash(0), cashIncome(0), cashlessIncome(0) {}

void Sale::SetCash(double amount) { cash = amount; }
double Sale::getCash() const { return cash; }

void Sale::Selling(Storage& storage) {
    storage.ShowStorage(0);
    std::vector<Product>& prods = storage.getProducts();
    double totalSum = 0;
    std::string input;

    while (true) {
        unsigned int id = 0, count = 0;

        std::cout << "\nВведите ID товара (0 для завершения чека): ";
        std::getline(std::cin, input);

        if (!isNumberSale(input)) {
            std::cout << "[ОШИБКА] Введите корректный ID (только цифры)!\n";
            continue;
        }

        id = std::stoul(input);
        if (id == 0) break;

        bool found = false;
        for (int i = 0; i < prods.size(); i++) {
            if (prods[i].getId() == id) {
                found = true;

                std::cout << "Количество (макс " << prods[i].getCount() << "): ";
                std::getline(std::cin, input);

                if (!isNumberSale(input)) {
                    std::cout << "[ОШИБКА] Введите целое число!\n";
                }
                else {
                    count = std::stoul(input);
                    if (count > 0 && count <= prods[i].getCount()) {
                        prods[i].setCount(prods[i].getCount() - count);
                        check.CheckPushBack(Product(prods[i].getId(), prods[i].getName(), prods[i].getPrice(), count));
                        totalSum += prods[i].getPrice() * count;
                        std::cout << "[УСПЕХ] Добавлено в чек.\n";
                    }
                    else {
                        std::cout << "Ошибка: Неверное количество (недостаточно на складе)!\n";
                    }
                }
                break;
            }
        }
        if (!found) std::cout << "Товар не найден!\n";
    }

    if (totalSum > 0) {
        int payType = 0;
        while (true) {
            std::cout << "\nСумма к оплате: " << totalSum << " руб.\n1 - Наличные\n2 - Карта\nОплата: ";
            std::getline(std::cin, input);

            if (isNumberSale(input)) {
                payType = std::stoi(input);
                if (payType == 1 || payType == 2) break;
            }
            std::cout << "[ОШИБКА] Выберите 1 или 2!\n";
        }

        if (payType == 1) cashIncome += totalSum;
        else cashlessIncome += totalSum;

        check.PrintCheck(totalSum);
        storage.SaveToFile();
    }
}

void Sale::ShowIncome() const {
    std::cout << "\n--- СТАТИСТИКА ДОХОДОВ ---\n";
    std::cout << "Наличные: " << cashIncome << " руб.\n";
    std::cout << "Безнал: " << cashlessIncome << " руб.\n";
    std::cout << "Общая выручка: " << (cashIncome + cashlessIncome) << " руб.\n";

    std::cout << "\nНажмите Enter, чтобы вернуться в меню...";

}

void Sale::StorageReturner(Storage& storage) {
    std::cout << "Модуль возврата товара в разработке...\n";
}