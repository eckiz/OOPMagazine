#include "Account.hpp"
#include <iostream>

void Account::ShowUsers(int mode) {
    std::cout << "\n--- Список пользователей ---" << std::endl;
    // В реальной версии здесь проход по вектору из Shop
    // mode 0 показывает всё, mode 1 — только логины
}

void Account::AddNewUser() {
    std::string l, p;
    std::cout << "Введите логин нового пользователя: "; std::cin >> l;
    std::cout << "Введите пароль: "; std::cin >> p;
    std::cout << "Пользователь добавлен!" << std::endl;
}

void Account::DeleteUser() {
    unsigned int id;
    std::cout << "Введите ID для удаления: "; std::cin >> id;
    std::cout << "Пользователь удален!" << std::endl;
}

void Account::ChangePass() {
    std::cout << "Пароль успешно изменен!" << std::endl;
}