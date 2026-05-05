#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <vector>

class User; // Предварительное объявление

class Account {
public:
    void AddNewUser();
    void DeleteUser();
    void ShowUsers(int mode = 0); // mode 0 - админ, 1 - кратко
    void ChangePass();
    // Прочие методы из схемы...
};

#endif