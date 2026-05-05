#include "SuperAdmin.hpp"
#include "Official.hpp"
#include "Account.hpp"
#include "Storage.hpp"
#include "Sale.hpp"
#include <iostream>

void SuperAdmin::ShowMenu() {
    int choice;
    do {
        std::cout << "\n========== ПАНЕЛЬ СУПЕР-АДМИНИСТРАТОРА ==========" << std::endl;
        std::cout << "Статус: " << status << " | ID: " << id << std::endl;
        std::cout << "1. Полное управление аккаунтами (вкл. Админов)" << std::endl;
        std::cout << "2. Управление складом телефонов" << std::endl;
        std::cout << "3. Просмотр финансовой аналитики" << std::endl;
        std::cout << "0. Выход из системы" << std::endl;
        std::cout << "=================================================" << std::endl;
        std::cout << "Выбор: ";

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        handleSuperChoice(choice);
    } while (choice != 0);
}

void SuperAdmin::handleSuperChoice(int choice) {
    if (getOfficial() == nullptr) return;

    switch (choice) {
    case 1:
        getOfficial()->getAccount()->ShowUsers(0);
        break;
    case 2:
        getOfficial()->getStorage()->ShowStorage(0);
        break;
    case 3:
        getOfficial()->getSale()->ShowIncome();
        break;
    case 0:
        std::cout << "Сессия Super Admin завершена." << std::endl;
        break;
    default:
        std::cout << "Ошибка: неверная команда." << std::endl;
    }
}