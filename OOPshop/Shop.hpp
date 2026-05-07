#ifndef SHOP_HPP
#define SHOP_HPP
#include <iostream>
#include <vector>
#include "User.hpp"
#include "Official.hpp"


class Shop {
private:
    std::vector<User*> users;
    Official* official;
public:
    Shop();
    ~Shop();
    void Start();
    bool Login();
    void CompletionUsersVector();
};

#endif