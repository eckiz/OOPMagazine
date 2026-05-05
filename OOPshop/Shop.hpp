#ifndef SHOP
#define SHOP

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