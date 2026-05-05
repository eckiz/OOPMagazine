#include "SuperAdmin.hpp"
#include "Official.hpp"
#include <iostream>

SuperAdmin::SuperAdmin(std::string l, std::string p, unsigned int i, Official* off)
    : Admin(l, p, i, off) {
    status = "SuperAdmin";
}

void SuperAdmin::ShowMenu() {
    int c;
    do {
        
        std::cout << "\n--- МЕНЮ SUPER ADMIN ---\n"
            << "1. Работа со складом\n"
            << "2. Продажи и чеки\n"
            << "3. Управление персоналом (полный доступ)\n"
            << "4. Финансовый отчет\n"
            << "0. Выход\n>> ";

        // Защита от ввода букв
        if (!(std::cin >> c)) {
            std::cout << "\n[ОШИБКА] Введите цифру из меню!\n";
            std::cin.clear();
            while (std::cin.get() != '\n');
            continue;
        }

        // 1. Работа со складом
        if (c == 1) {
            std::cout << "\n--- СКЛАД ---\n1-Добавить товар, 2-Удалить товар, 3-Просмотр, 4-Изменить цену, 0-Назад: ";
            int act;
            if (!(std::cin >> act)) {
                std::cin.clear();
                while (std::cin.get() != '\n');
                continue;
            }
            if (act == 1) official->getStorage().AddNewItem();
            else if (act == 2) official->getStorage().DeleteItem();
            else if (act == 3) official->getStorage().ShowStorage(0);
            else if (act == 4) official->getStorage().ChangePrice();
        }

        // 2. Продажи и чеки
        else if (c == 2) {
            official->getSale().Selling(official->getStorage());
        }

        // 3. Управление персоналом
        else if (c == 3) {
            std::cout << "\n--- ПЕРСОНАЛ ---\n1-Новый юзер, 2-Удалить юзера, 3-Список, 4-Сменить пароль: ";
            int act;
            if (!(std::cin >> act)) {
                std::cin.clear();
                while (std::cin.get() != '\n');
                continue;
            }
            if (act == 1) official->getAccount().AddNewUser(*official->getUsers(), official);
            else if (act == 2) official->getAccount().DeleteUser(*official->getUsers());
            else if (act == 3) official->getAccount().ShowUsers(*official->getUsers(), 0);
            else if (act == 4) official->getAccount().ChangeUserPass(*official->getUsers(), this->status);
        }

        // 4. Финансовый отчет
        else if (c == 4) {
            official->getSale().ShowIncome();
        }

    } while (c != 0);
}