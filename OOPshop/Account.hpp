#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP
#include <vector>
#include <string>

class User;
class Official;

class Account {
public:
    void AddNewUser(std::vector<User*>& users, Official* official);
    void DeleteUser(std::vector<User*>& users);
    void ShowUsers(const std::vector<User*>& users, int mode);
    void ChangePass(User* user);
    User* CheckLogin(const std::vector<User*>& users, const std::string& login, const std::string& pass);
    void ChangeUserAccounts(std::vector<User*>& users);
    void ChangeUserPass(std::vector<User*>& users, const std::string& requesterStatus);
    void SaveUsers(const std::vector<User*>& users);
};
#endif