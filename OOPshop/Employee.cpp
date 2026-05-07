#include "Admin.hpp"
#include "SuperAdmin.hpp"
#include "Employee.hpp"
#include "Official.hpp"
#include <iostream>
#include <string>


Employee::Employee(std::string l, std::string p, unsigned int i, Official* off)
    : User(l, p, "Employee", i, off) {
}

void Employee::ShowMenu() {
    std::string input;
    int c = -1;

    do {
        std::cout << "\n--- МЕНЮ ПРОДАВЦА ---\n"
            << "1. Новая продажа\n"
            << "2. Посмотреть склад\n"
            << "0. Выход\n>> ";

        std::getline(std::cin, input);


        bool isDigit = true;
        if (input.empty()) isDigit = false;
        for (int i = 0; i < input.length(); i++) {
            if (input[i] < '0' || input[i] > '9') {
                isDigit = false;
                break;
            }
        }

        if (!isDigit) {
            std::cout << "[ОШИБКА] Пожалуйста, введите цифру (0, 1 или 2)!\n";
            continue;
        }


        c = std::stoi(input);

        if (c == 1) {
            official->getSale().Selling(official->getStorage());
        }
        else if (c == 2) {
            official->getStorage().ShowStorage(0);
            std::cout << "\nНажмите Enter, чтобы продолжить...";
            std::cin.get();
        }
        else if (c != 0) {
            std::cout << "Нет такого пункта меню.\n";
        }

    } while (c != 0);
}