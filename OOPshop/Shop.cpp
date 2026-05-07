#include "Official.hpp"
#include "Shop.hpp"
#include "SuperAdmin.hpp"
#include "Employee.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

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
    system("cls");
    std::string login, pass;
    std::cout << "\n--- АВТОРИЗАЦИЯ ---\n";
    std::cout << "Login: ";
    std::getline(std::cin, login);
    std::cout << "Password: ";
    std::getline(std::cin, pass);
    system("cls");

    for (auto u : users) {
        if (u->getLogin() == login && u->getPassword() == pass) {
            std::cout << "Добро пожаловать, " << u->getLogin() << "!\n";
            u->ShowMenu();
            official->Logout();
            return true;
        }
    }
    std::cout << "Неверный логин или пароль.\n";
    return false;
}

static bool isNumberSimple(std::string s) {
    if (s.empty()) return false;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] < '0' || s[i] > '9') return false;
    }
    return true;
}

void Shop::Start() {
    std::string input;
    int choice = -1;

    while (true) {
        system("cls");
        std::cout << "\n=== Phone Shop ===\n"
            << "1. Войти\n"
            << "2. Выход\n"
            << ">> ";

        std::getline(std::cin, input);

        if (!isNumberSimple(input)) {
            std::cout << "[ОШИБКА] Пожалуйста, введите цифру 1 или 2!\n";
            continue;
        }

        choice = std::stoi(input);

        if (choice == 1) {
            Login();
            break;
        }
        else if (choice == 2) {
            std::cout << "Завершение работы...\n";
            exit(0);
        }
        else {
            std::cout << "Нет такого пункта!\n";
        }
    }
}