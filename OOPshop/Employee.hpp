#ifndef EMPLOYEE
#define EMPLOYEE
#include "User.hpp"

class Employee : public User {
public:
    Employee(std::string l, std::string p, unsigned int i, Official* off);
    void ShowMenu() override;
};
#endif 