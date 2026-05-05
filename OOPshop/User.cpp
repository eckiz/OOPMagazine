#include "User.hpp"

User::User(std::string log, std::string pass, std::string stat, unsigned int userId)
    : login(log), password(pass), status(stat), id(userId), official(nullptr) {
}

User::~User() {}

std::string User::getLogin() const { return login; }
std::string User::getPassword() const { return password; }
std::string User::getStatus() const { return status; }
Official* User::getOfficial() const { return official; }

void User::setOfficial(Official* off) { official = off; }