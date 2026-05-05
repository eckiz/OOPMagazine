#include "Check.hpp"
#include <iostream>

void Check::CheckPushBack(const Product& p) {
    products.push_back(p);
}

void Check::PrintCheck(double totalSum) {
    std::cout << "\n********** вей **********" << std::endl;
    for (const auto& p : products) {
        std::cout << p.getName() << " .......... " << p.getPrice() << std::endl;
    }
    std::cout << "*************************" << std::endl;
    std::cout << "хрнцн: " << totalSum << std::endl;
}