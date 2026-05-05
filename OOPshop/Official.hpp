#pragma once
#include "Account.hpp"
#include "Storage.hpp"
#include "Sale.hpp"
#include <vector>

class User;

class Official {
private:
    Account account;
    Storage storage;
    Sale sale;
    std::vector<User*>* usersRef; // —сылка на глобальный список пользователей
public:
    Official(std::vector<User*>* users);
    void Logout();
    Account& getAccount();
    Storage& getStorage();
    Sale& getSale();
    std::vector<User*>* getUsers();
};