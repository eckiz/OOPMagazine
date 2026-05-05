#ifndef SALE_HPP
#define SALE_HPP

#include "Check.hpp"

class Storage;

class Sale {
private:
    double cash;
    double cashIncome;
    double cashIncmone; // Опечатка из твоей схемы сохранена для соответствия
    Check check;

public:
    Sale();
    void Selling(Storage* storage);
    void ShowIncome() const;
    double getCash() const;
    void setCash(double c);
};

#endif