#ifndef SHOP_HPP
#define SHOP_HPP

#include <vector>
#include "User.hpp"
#include "Official.hpp" // Обязательно добавляем этот инклюд

class Shop {
private:
    std::vector<User*> users;

public:
    Shop() = default;
    ~Shop();

    void Start();
    bool Login();
    // Изменяем сигнатуру: добавляем аргумент Official*
    void CompletionUsersVector(Official* off);
};

#endif