#ifndef USERS

#define USERS

#include <string>

class Official;

class User {
protected:
    std::string login;
    std::string password;
    std::string status;
    unsigned int id;
    double sales;
    Official* official;
public:
    User(std::string l, std::string p, std::string s, unsigned int i, Official* off);
    virtual ~User() = default;

    std::string getLogin() const;
    std::string getPassword() const;
    std::string getStatus() const;
    unsigned int getId() const;
    void setPassword(const std::string& newPass);

    virtual void ShowMenu() = 0;
};
#endif 