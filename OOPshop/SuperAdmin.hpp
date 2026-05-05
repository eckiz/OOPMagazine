#ifndef SUPERADMIN_HPP
#define SUPERADMIN_HPP

#include "User.hpp"

class SuperAdmin : public User {
private:
    std::string status;

public:
    //  онструктор: инициализирует базу и ставит статус Super Admin по умолчанию
    SuperAdmin(std::string log, std::string pass, unsigned int id)
        : User(log, pass, "Super Admin", id), status("Super Admin") {
    }

    // ѕереопределение виртуального метода меню
    void ShowMenu() override;

private:
    void handleSuperChoice(int choice);
};

#endif