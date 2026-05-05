#include "Official.hpp"

Official::Official() {
    accounts = new Account();
    storage = new Storage();
    sale = new Sale();
}

Official::~Official() {
    delete accounts;
    delete storage;
    delete sale;
}

Account* Official::getAccount() const { return accounts; }
Storage* Official::getStorage() const { return storage; }
Sale* Official::getSale() const { return sale; }

void Official::Logout() {
    // Логика выхода, если нужно сбросить временные данные
}