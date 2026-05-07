#include "SuperAdmin.hpp"
#include "Official.hpp"
#include <iostream>
#include <string>


static bool isNumberSA(const std::string& s) {
    if (s.empty()) return false;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] < '0' || s[i] > '9') return false;
    }
    return true;
}

SuperAdmin::SuperAdmin(std::string l, std::string p, unsigned int i, Official* off)
    : Admin(l, p, i, off) {
    status = "SuperAdmin";
}

void SuperAdmin::ShowMenu() {
    std::string input;
    int c = -1;

    do {
        system("cls");

        std::cout << "--- МЕНЮ SUPER ADMIN ---\n"
            << "1. Работа со складом\n"
            << "2. Продажи и чеки\n"
            << "3. Управление персоналом (полный доступ)\n"
            << "4. Финансовый отчет\n"
            << "0. Выход\n>> ";

        std::getline(std::cin, input);

        if (!isNumberSA(input)) {
            std::cout << "\n[ОШИБКА] Введите корректное число!\n";
            std::cout << "Нажмите Enter для продолжения...";
            std::cin.get();
            continue;
        }

        c = std::stoi(input);

        if (c == 1) {
            system("cls");
            std::cout << "--- СКЛАД ---\n"
                << "1-Добавить товар, 2-Удалить товар, 3-Просмотр, 4-Изменить цену, 5-Изменить название, 0-Назад\n>> ";

            std::string act_input;
            std::getline(std::cin, act_input);

            if (isNumberSA(act_input)) {
                int act = std::stoi(act_input);
                if (act == 1) official->getStorage().AddNewItem();
                else if (act == 2) official->getStorage().DeleteItem();
                else if (act == 3) {
                    official->getStorage().ShowStorage(0);
                    std::cout << "\nНажмите Enter для продолжения...";
                    std::cin.get();
                }
                else if (act == 4) official->getStorage().ChangePrice();
                else if (act == 5) official->getStorage().ChangeName();
            }
        }
        else if (c == 2) {
            system("cls");
            official->getSale().Selling(official->getStorage());
            std::cout << "\nНажмите Enter для возврата...";
            std::cin.get();
        }
        else if (c == 3) {
            system("cls");
            std::cout << "--- ПЕРСОНАЛ ---\n"
                << "1-Новый юзер, 2-Удалить юзера, 3-Список, 4-Сменить пароль, 0-Назад\n>> ";

            std::string act_input;
            std::getline(std::cin, act_input);

            if (isNumberSA(act_input)) {
                int act = std::stoi(act_input);
                if (act == 1) official->getAccount().AddNewUser(*official->getUsers(), official);
                else if (act == 2) official->getAccount().DeleteUser(*official->getUsers());
                else if (act == 3) {
                    official->getAccount().ShowUsers(*official->getUsers(), 0);
                    std::cout << "\nНажмите Enter для продолжения...";
                    std::cin.get();
                }
                else if (act == 4) official->getAccount().ChangeUserPass(*official->getUsers(), this->status);
            }
        }
        else if (c == 4) {
            system("cls");
            official->getSale().ShowIncome();
            std::cout << "\nНажмите Enter для возврата...";
            std::cin.get();
        }

    } while (c != 0);
}