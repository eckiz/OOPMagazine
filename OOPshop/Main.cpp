#include "Shop.hpp"
#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#endif

int main() {
#ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif

    Shop myShop;
    myShop.Start();

    return 0;
}