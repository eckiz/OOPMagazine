#include "Account.hpp"
#include "User.hpp"
#include "Official.hpp"
#include "Employee.hpp"
#include "Admin.hpp"
#include <iostream>

//User
User::User(std::string l, std::string p, std::string s, unsigned int i, Official* off)
    : login(l), password(p), status(s), id(i), sales(0.0), official(off) {
}

std::string User::getLogin() const { return login; }
std::string User::getPassword() const { return password; }
std::string User::getStatus() const { return status; }
unsigned int User::getId() const { return id; }
void User::setPassword(const std::string& newPass) { password = newPass; }