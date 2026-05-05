#pragma once
#include "Check.hpp"
#include "Storage.hpp"

class Sale {
private:
    double cash;
    double cashIncome;
    double cashlessIncome;
    Check check;
public:
    Sale();
    void SetCash(double amount);
    double getCash() const;
    void Selling(Storage& storage);
    void ShowIncome() const;
    void StorageReturner(Storage& storage);
};