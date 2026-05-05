#include "include.hpp"
#include "User.hpp"
#include "Official.hpp"
 
class Admin : public User {
private:
    std::string status;

public:
    Admin(std::string log, std::string pass, unsigned int id)
        : User(log, pass, "Admin", id) {
        this->status = "Admin";
    }

    // Реализация меню администратора
    void ShowMenu() override {
        int choice;
        do {
            std::cout << "\nМЕНЮ АДМИНИСТРАТОРА" << "/n";
            std::cout << "1. Управление пользователями" << "/n";
            std::cout << "2. Управление складом" << "/n";
            std::cout << "3. Просмотр отчетов" << "/n";
            std::cout << "0. Выход" << "/n";
            std::cout << "Выбор >> ";
            std::cin >> choice;

            handleMenuChoice(choice);
        } 
        while
            (choice != 0);
    }

private:
    void handleMenuChoice(int choice) {
        //тута админ крч в офишал секс
        if (choice == 1) {
            getOfficial()->getAccount()->ShowUsers();
        }
        else if (choice == 2) {
            getOfficial()->getStorage()->ShowStorage();
        }
        else if (choice == 3) {
           getOfficial()->getSale()->ShowIncome();
        }
        else if (choice == 0) {
            std::cout << "Выход из сессии" << "/n";
        }
        else {
            std::cout << "Ошибка: неверный пункт!" << "/n";
        }
    }
};