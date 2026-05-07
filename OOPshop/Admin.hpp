#ifndef ADMIN_HPP
#define ADMIN_HPP
#include "User.hpp"

class Admin : public User {
public:
    Admin(std::string l, std::string p, unsigned int i, Official* off);
    void ShowMenu() override;
};
#endif  