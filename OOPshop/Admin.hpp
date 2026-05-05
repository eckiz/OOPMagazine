#ifndef ADMIN_HPP
#define ADMIN_HPP

#include "User.hpp"
#include "include.hpp"
#include "Official.hpp"
//эт класс
class Admin : public User {
private:
    //статус 
    std::string status;
public:
    //типо сессия 
    Admin(std::string log, std::string pass, unsigned int id)
        : User(log, pass, "Admin", id), status("Admin") {
    }

    void ShowMenu() override;

private:
    // Вспомогательный метод для обработки выбора (чтобы не загромождать ShowMenu)
    void handleMenuChoice(int choice);
};

#endif