#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP
#include "User.hpp"

class Employee : public User {
public:
    Employee(std::string l, std::string p, unsigned int i, Official* off);
    void ShowMenu() override;
};
#endif 