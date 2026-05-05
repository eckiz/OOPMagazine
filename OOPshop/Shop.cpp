#include "Shop.hpp"
#include "Admin.hpp"
#include "SuperAdmin.hpp"
#include "Employee.hpp"
#include <iostream>

Shop::~Shop() {
    for (User* u : users) delete u;
    users.clear();
}

void Shop::CompletionUsersVector(Official* off) {
    // Создаем админа
    User* a = new Admin("admin", "1234", 1);
    a->setOfficial(off); // Устанавливаем связь с системой
    users.push_back(a);

    // Создаем супер-админа
    User* sa = new SuperAdmin("god", "root", 777);
    sa->setOfficial(off);
    users.push_back(sa);
}

// ... остальная логика Login и Start ...