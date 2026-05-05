#include "Official.hpp"
#include "Shop.hpp"
#include "SuperAdmin.hpp"
#include "Employee.hpp"
#include <iostream>

// --- Shop ---
Shop::Shop() {
    official = new Official(&users);
    CompletionUsersVector();
}

Shop::~Shop() {
    for (auto u : users) delete u;
    delete official;
}

void Shop::CompletionUsersVector() {
    users.push_back(new SuperAdmin("root", "root", 1, official));
    users.push_back(new Employee("user", "123", 2, official));
}

bool Shop::Login() {
    std::string l, p;
    std::cout << "\n--- АВТОРИЗАЦИЯ ---\nЛогин: "; std::cin >> l;
    std::cout << "Пароль: "; std::cin >> p;

    for (auto u : users) {
        if (u->getLogin() == l && u->getPassword() == p) {
            std::cout << "Добро пожаловать, " << u->getLogin() << "!\n";
            u->ShowMenu();
            official->Logout();
            return true;
        }
    }
    std::cout << "Неверный логин или пароль.\n";
    return false;
}

void Shop::Start() {
    int c;
    while (true) {
        std::cout << "\n1. Войти\n2. Выход\n>> ";
        std::cin >> c;
        if (c == 1) Login();
        else if (c == 2) break;
    }
}