#ifndef USER_HPP
#define USER_HPP

#include "include.hpp"

class Official;

class User {
protected:
    std::string login;
    std::string password;
    std::string status;
    unsigned int id;
    Official* official;

public:
    User(std::string log, std::string pass, std::string stat, unsigned int userId);
    virtual ~User();

    virtual void ShowMenu() = 0; 

    std::string getLogin() const;
    std::string getPassword() const;
    std::string getStatus() const;
    Official* getOfficial() const;

    void setOfficial(Official* off);
};

#endif