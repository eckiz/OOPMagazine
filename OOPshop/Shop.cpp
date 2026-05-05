#include "Official.hpp"
#include "Shop.hpp"
#include "SuperAdmin.hpp"
#include "Employee.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
//Shop
Shop::Shop() {
    official = new Official(&users);
    CompletionUsersVector();
}

Shop::~Shop() {
    for (auto u : users) delete u;
    delete official;
}

void Shop::CompletionUsersVector() {
    std::ifstream in("users.txt");


    if (!in.is_open()) {
            users.push_back(new SuperAdmin("root", "root", 1, official));
            users.push_back(new Employee("user", "123", 2, official));

        official->getAccount().SaveUsers(users); 
    }
    else {
        std::string line;
        while (std::getline(in, line)) {
            if (line.empty()) continue;
            std::stringstream ss(line);
            std::string item, login, pass, status;
            unsigned int id;

            std::getline(ss, item, ';'); id = std::stoul(item);
            std::getline(ss, login, ';');
            std::getline(ss, pass, ';');
            std::getline(ss, status, ';');

            
            if (status == "SuperAdmin") users.push_back(new SuperAdmin(login, pass, id, official));
            else if (status == "Admin") users.push_back(new Admin(login, pass, id, official));
            else if (status == "Employee") users.push_back(new Employee(login, pass, id, official));
        }
        in.close();
    }


    official->getStorage().LoadFromFile();
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