#ifndef OFFICIAL_H
#define OFFICIAL_H

#include "Account.hpp"
#include "Storage.hpp"
#include "Sale.hpp"

class Official {
private:
    Account* accounts;
    Storage* storage;
    Sale* sale;

public:
    Official();
    ~Official();

    void Logout(); // Очистка сессии

    // Геттеры согласно схеме (const)
    Account* getAccount() const;
    Storage* getStorage() const;
    Sale* getSale() const;
};

#endif