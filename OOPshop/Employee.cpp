#include "Admin.hpp"
#include "SuperAdmin.hpp"
#include "Employee.hpp"
#include "Official.hpp"
#include <iostream>

// --- Employee ---
Employee::Employee(std::string l, std::string p, unsigned int i, Official* off)
    : User(l, p, "Employee", i, off) {
}

void Employee::ShowMenu() {
    int c;
    do {
        std::cout << "\n--- МЕНЮ ПРОДАВЦА ---\n1. Новая продажа\n2. Посмотреть склад\n0. Выход\n>> ";
        std::cin >> c;
        if (c == 1) official->getSale().Selling(official->getStorage());
        if (c == 2) official->getStorage().ShowStorage(0);
    } while (c != 0);
}