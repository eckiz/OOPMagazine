#include "Employee.hpp"
//#include "Official.hpp"
//#include "Storage.hpp"
//#include "Sale.hpp"
#include <iostream>

void Employee::ShowMenu() {
    int choice;
    do {
        std::cout << "\n--- РАБОЧЕЕ МЕСТО СОТРУДНИКА ---" << std::endl;
        std::cout << "Логин: " << getLogin() << " | Роль: " << getStatus() << std::endl;
        std::cout << "1. Просмотр наличия телефонов (Storage)" << std::endl;
        std::cout << "2. Оформить продажу (Sale)" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Выбор: ";

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        handleEmployeeChoice(choice);
    } while (choice != 0);
}

void Employee::handleEmployeeChoice(int choice) { 
    if (getOfficial() == nullptr) return;

    switch (choice) {
    case 1:
        // Сотрудник видит склад в режиме клиента/продавца (например, mode 1)
        getOfficial()->getStorage()->ShowStorage(1);
        break;
    case 2:
        // Вызов метода продажи из класса Sale
        getOfficial()->getSale()->Selling(0);
        break;
    case 0:
        std::cout << "Завершение смены..." << std::endl;
        break;
    default:
        std::cout << "Неверный пункт!" << std::endl;
    }
}