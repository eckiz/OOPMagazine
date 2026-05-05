#include "Official.hpp"
#include "Shop.hpp"
#include "SuperAdmin.hpp"
#include "Employee.hpp"
#include <iostream>

//Official
Official::Official(std::vector<User*>* u) : usersRef(u) {
    storage.CreateStorage();
}
void Official::Logout() { std::cout << "Выход из аккаунта...\n"; }
Account& Official::getAccount() { return account; }
Storage& Official::getStorage() { return storage; }
Sale& Official::getSale() { return sale; }
std::vector<User*>* Official::getUsers() { return usersRef; }