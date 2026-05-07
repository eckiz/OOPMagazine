#include "Account.hpp"
#include "User.hpp"
#include "Official.hpp"
#include "Employee.hpp"
#include "Admin.hpp"
#include <iostream>
#include <fstream>
#include <string>


static bool isNumberValid(std::string s) {
    if (s.empty()) return false;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] < '0' || s[i] > '9') return false;
    }
    return true;
}


void Account::ShowUsers(const std::vector<User*>& users, int mode) {
    std::cout << "\n--- СПИСОК ПОЛЬЗОВАТЕЛЕЙ ---\n";
    for (int i = 0; i < users.size(); i++) {
        std::cout << "[" << users[i]->getId() << "] " << users[i]->getLogin()
            << " (" << users[i]->getStatus() << ")\n";
    }
}


User* Account::CheckLogin(const std::vector<User*>& users, const std::string& login, const std::string& pass) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i]->getLogin() == login && users[i]->getPassword() == pass) {
            return users[i];
        }
    }
    return nullptr;
}


void Account::ChangePass(User* user) {
    if (!user) return;
    std::string newPass;
    std::cout << "Введите новый пароль для себя: ";
    std::getline(std::cin, newPass);
    user->setPassword(newPass);
    std::cout << "[УСПЕХ] Ваш пароль изменен.\n";
}


void Account::ChangeUserPass(std::vector<User*>& users, const std::string& requesterStatus) {
    std::string input, newPass;
    std::cout << "Введите ID пользователя для смены пароля: ";
    std::getline(std::cin, input);

    if (!isNumberValid(input)) {
        std::cout << "Ошибка: ID должен быть числом.\n";
        return;
    }

    unsigned int targetId = std::stoul(input);
    for (int i = 0; i < users.size(); i++) {
        if (users[i]->getId() == targetId) {
            if (requesterStatus == "SuperAdmin" || (requesterStatus == "Admin" && users[i]->getStatus() == "Employee")) {
                std::cout << "Новый пароль для " << users[i]->getLogin() << ": ";
                std::getline(std::cin, newPass);
                users[i]->setPassword(newPass);
                std::cout << "[УСПЕХ] Пароль изменен.\n";
                SaveUsers(users);
            }
            else {
                std::cout << "[ОТКАЗ] Недостаточно прав.\n";
            }
            return;
        }
    }
    std::cout << "Пользователь не найден.\n";
}


void Account::AddNewUser(std::vector<User*>& users, Official* official) {
    std::string l, p, input;
    int role = 0;

    // 1. Ввод и проверка логина
    while (true) {
        std::cout << "Введите логин нового пользователя: ";
        std::getline(std::cin, l);

        if (l.empty()) {
            std::cout << "[ОШИБКА] Логин не может быть пустым!\n";
            continue;
        }

        bool loginExists = false;
        // Проверяем по всему списку пользователей
        for (int i = 0; i < users.size(); i++) {
            if (users[i]->getLogin() == l) {
                loginExists = true;
                break;
            }
        }

        if (loginExists) {
            std::cout << "[ОШИБКА] Пользователь с логином \"" << l << "\" уже зарегистрирован!\n";
            // Если хотим дать возможность попробовать другой логин, оставляем в цикле.
            // Если хотим прервать операцию (как было раньше), пишем return;
            continue;
        }

        break; // Логин уникален, выходим из цикла проверки
    }

    // 2. Ввод пароля
    std::cout << "Введите пароль: ";
    std::getline(std::cin, p);

    // 3. Ввод роли (с твоей прошлой правкой)
    while (true) {
        std::cout << "Выберите роль (1 - Продавец, 2 - Админ): ";
        std::getline(std::cin, input);

        if (input == "1") {
            role = 1;
            break;
        }
        else if (input == "2") {
            role = 2;
            break;
        }
        else {
            std::cout << "[ОШИБКА] Неверный ввод! Введите 1 или 2.\n";
        }
    }

    // 4. Создание пользователя
    unsigned int newId = users.empty() ? 1 : users.back()->getId() + 1;

    if (role == 2) {
        users.push_back(new Admin(l, p, newId, official));
        std::cout << "[УСПЕХ] Админ \"" << l << "\" добавлен.\n";
    }
    else {
        users.push_back(new Employee(l, p, newId, official));
        std::cout << "[УСПЕХ] Продавец \"" << l << "\" добавлен.\n";
    }

    SaveUsers(users);
}

void Account::DeleteUser(std::vector<User*>& users) {
    std::string input;
    std::cout << "ID для удаления: "; std::getline(std::cin, input);
    if (!isNumberValid(input)) return;

    unsigned int id = std::stoul(input);
    for (auto it = users.begin(); it != users.end(); ++it) {
        if ((*it)->getId() == id && (*it)->getStatus() != "SuperAdmin") {
            delete* it;
            users.erase(it);
            SaveUsers(users);
            std::cout << "Удалено.\n";
            return;
        }
    }
}
void Account::SaveUsers(const std::vector<User*>& users) {
    std::ofstream out("users.txt");
    if (out.is_open()) {
        for (int i = 0; i < users.size(); i++) {
            out << users[i]->getId() << ";"
                << users[i]->getLogin() << ";"
                << users[i]->getPassword() << ";"
                << users[i]->getStatus() << "\n";
        }
    }
    out.close();
}