#include "Admin.hpp"
#include "SuperAdmin.hpp"
#include "Employee.hpp"
#include "Official.hpp"
#include <iostream>

//Admin
Admin::Admin(std::string l, std::string p, unsigned int i, Official* off)
    : User(l, p, "Admin", i, off) {
}

void Admin::ShowMenu() {
    int choice;
    do {
        std::cout << "\n--- МЕНЮ АДМИНА ---\n"
            << "1. Склад\n"
            << "2. Продажи\n"
            << "3. Управление Пользователями\n"
            << "4. Отчет по доходам\n"
            << "0. Выход\n>> ";

        if (!(std::cin >> choice)) {
            std::cout << "\n[ОШИБКА] Введите цифру из списка!\n";
            std::cin.clear();
            while (std::cin.get() != '\n');
            continue;
        }

        if (choice == 1) {
            std::cout << "1-Добавить товар, 2-Удалить товар, 3-Показать склад, 4-Изменить название: ";
            int act;
            if (!(std::cin >> act)) {
                std::cin.clear();
                while (std::cin.get() != '\n');
                continue;
            }

            if (act == 1) official->getStorage().AddNewItem();
            else if (act == 2) official->getStorage().DeleteItem();
            else if (act == 3) official->getStorage().ShowStorage(0);
            else if (act == 4) official->getStorage().ChangeName();
            
        }
        else if (choice == 2) {
            official->getSale().Selling(official->getStorage());
        }
        else if (choice == 3) {
            std::cout << "1-Добавить юзера, 2-Удалить юзера, 3-Показать список,4-Сменить пароль ПОЛЬЗОВАТЕЛЮ: ";
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
        else if (choice == 4) {
            official->getSale().ShowIncome();
        }

    } while (choice != 0);
}