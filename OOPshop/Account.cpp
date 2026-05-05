#include "Account.hpp"
#include "User.hpp"
#include "Official.hpp"
#include "Employee.hpp"
#include "Admin.hpp"
#include <iostream>

// --- Account ---
void Account::ShowUsers(const std::vector<User*>& users, int mode) {
    std::cout << "\n--- СПИСОК ПОЛЬЗОВАТЕЛЕЙ ---\n";
    for (auto u : users) {
        std::cout << "[" << u->getId() << "] " << u->getLogin() << " (" << u->getStatus() << ")\n";
    }
}

void Account::AddNewUser(std::vector<User*>& users, Official* official) {
    std::string l, p;
    int role;

    std::cout << "Введите логин нового пользователя: ";
    std::cin >> l;

    // --- ПРОВЕРКА НА УНИКАЛЬНОСТЬ ---
    for (const auto& u : users) {
        if (u->getLogin() == l) {
            std::cout << "\n[ОШИБКА] Пользователь с логином \"" << l << "\" уже зарегистрирован!\n";
            std::cout << "Операция отменена.\n";
            return; // Выходим из метода, не запрашивая пароль и не создавая объект
        }
    }

    std::cout << "Введите пароль: ";
    std::cin >> p;

    std::cout << "Выберите роль (1 - Продавец, 2 - Админ): ";
    std::cin >> role;

    unsigned int newId = users.empty() ? 1 : users.back()->getId() + 1;

    if (role == 2) {
        users.push_back(new Admin(l, p, newId, official));
    }
    else {
        users.push_back(new Employee(l, p, newId, official));
    }

    std::cout << "[УСПЕХ] Пользователь \"" << l << "\" успешно добавлен в систему.\n";
}

void Account::DeleteUser(std::vector<User*>& users) {
    unsigned int id;
    std::cout << "ID для удаления: "; std::cin >> id;
    for (auto it = users.begin(); it != users.end(); ++it) {
        if ((*it)->getId() == id && (*it)->getStatus() != "SuperAdmin") {
            delete* it;
            users.erase(it);
            std::cout << "Пользователь удален!\n";
            return;
        }
    }
    std::cout << "Ошибка удаления (возможно это SuperAdmin или ID не найден).\n";
}
// В файле src/Account.cpp
void Account::ChangeUserPass(std::vector<User*>& users, const std::string& requesterStatus) {
    unsigned int targetId;
    std::cout << "Введите ID пользователя для смены пароля: ";
    std::cin >> targetId;

    bool found = false;
    for (size_t i = 0; i < users.size(); ++i) {
        if (users[i]->getId() == targetId) {
            found = true;
            std::string targetStatus = users[i]->getStatus();

            // Проверка прав доступа
            bool accessGranted = false;

            if (requesterStatus == "SuperAdmin") {
                // SuperAdmin может менять пароль Админам и Продавцам
                if (targetStatus == "Admin" || targetStatus == "Employee") {
                    accessGranted = true;
                }
                else if (targetStatus == "SuperAdmin" && users[i]->getId() == targetId) {
                    // Разрешаем менять свой собственный пароль
                    accessGranted = true;
                }
            }
            else if (requesterStatus == "Admin") {
                // Admin может менять пароль только Продавцам
                if (targetStatus == "Employee") {
                    accessGranted = true;
                }
                else {
                    std::cout << "[ОШИБКА] У вас нет прав менять пароль для роли: " << targetStatus << std::endl;
                }
            }

            if (accessGranted) {
                std::string newPass;
                std::cout << "Введите новый пароль для " << users[i]->getLogin() << ": ";
                std::cin >> newPass;
                users[i]->setPassword(newPass);
                std::cout << "[УСПЕХ] Пароль изменен." << std::endl;
            }
            return;
        }
    }

    if (!found) {
        std::cout << "[ОШИБКА] Пользователь с таким ID не найден." << std::endl;
    }
}