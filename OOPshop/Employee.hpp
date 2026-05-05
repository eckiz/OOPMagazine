#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include "User.hpp"
#include "Official.hpp"
class Employee : public User {
private:
    std::string status;

public:
    //  онструктор: автоматически передает статус "Employee" в базовый класс
    Employee(std::string log, std::string pass, unsigned int id)
        : User(log, pass, "Employee", id), status("Employee") {
    }

    // ѕереопределение метода меню дл€ сотрудника
    void ShowMenu() override;

private:
    // ќбработка действий сотрудника
    void handleEmployeeChoice(int choice);
};

#endif