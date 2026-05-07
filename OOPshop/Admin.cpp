#include "Admin.hpp"
#include "SuperAdmin.hpp"
#include "Employee.hpp"
#include "Official.hpp"
#include <iostream>
#include <string>

// Конструктор
Admin::Admin(std::string l, std::string p, unsigned int i, Official* off)
    : User(l, p, "Admin", i, off) {
}

void Admin::ShowMenu() {
    std::string input;
    int choice = -1;

    do {
        system("cls");
        std::cout << "\n--- МЕНЮ АДМИНА ---\n"
            << "1. Склад\n"
            << "2. Продажи\n"
            << "3. Управление Пользователями\n"
            << "4. Отчет по доходам\n"
            << "0. Выход\n>> ";

        std::getline(std::cin, input);
        system("cls");
        bool isDigit = true;
        if (input.empty()) isDigit = false;
        else {
            for (int i = 0; i < input.length(); i++) {
                if (input[i] < '0' || input[i] > '9') {
                    isDigit = false;
                    break;
                }
            }
        }

        if (!isDigit) {
            std::cout << "\n[ОШИБКА] Введите цифру из списка!\n";
            continue;
        }

        choice = std::stoi(input);

        if (choice == 1) {
            std::cout << "1-Добавить товар, 2-Удалить товар, 3-Показать склад, 4-Изменить название, 0-Назад: ";
            std::string act_input;
            std::getline(std::cin, act_input);

            // Проверка подменю
            bool actDigit = true;
            if (act_input.empty()) actDigit = false;
            else {
                for (int i = 0; i < act_input.length(); i++) {
                    if (act_input[i] < '0' || act_input[i] > '9') { actDigit = false; break; }
                }
            }

            if (actDigit) {
                int act = std::stoi(act_input);
                if (act == 1) official->getStorage().AddNewItem();
                else if (act == 2) official->getStorage().DeleteItem();
                else if (act == 3) {
                    official->getStorage().ShowStorage(0);
                    std::cout << "\nНажмите Enter..."; std::cin.get();
                }
                else if (act == 4) official->getStorage().ChangeName();
            }
        }
        else if (choice == 2) {
            official->getSale().Selling(official->getStorage());
        }
        else if (choice == 3) {
            std::cout << "1-Добавить юзера, 2-Удалить юзера, 3-Показать список, 4-Сменить пароль, 0-Назад: ";
            std::string act_input;
            std::getline(std::cin, act_input);

            bool actDigit = true;
            if (act_input.empty()) actDigit = false;
            else {
                for (int i = 0; i < act_input.length(); i++) {
                    if (act_input[i] < '0' || act_input[i] > '9') { actDigit = false; break; }
                }
            }

            if (actDigit) {
                int act = std::stoi(act_input);
                if (act == 1) official->getAccount().AddNewUser(*official->getUsers(), official);
                else if (act == 2) official->getAccount().DeleteUser(*official->getUsers());
                else if (act == 3) {
                    official->getAccount().ShowUsers(*official->getUsers(), 0);
                    std::cout << "\nНажмите Enter..."; std::cin.get();
                }
                else if (act == 4) official->getAccount().ChangeUserPass(*official->getUsers(), this->status);
            }
        }
        else if (choice == 4) {
            official->getSale().ShowIncome();
            std::cout << "\nНажмите Enter..."; std::cin.get();
        }

    } while (choice != 0);
}