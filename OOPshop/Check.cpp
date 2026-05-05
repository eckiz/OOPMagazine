#include "Check.hpp"
#include <iostream>

void Check::CheckPushBack(const Product& p) {
    products.push_back(p);
}

void Check::PrintCheck(double totalSum) {
    std::cout << "\n========== ÔÈÑÊÀËÜÍÛÉ ×ÅÊ ==========\n";
    for (const auto& p : products) {
        std::cout << p.getName() << " x" << p.getCount() << " | " << p.getPrice() * p.getCount() << " ðóá.\n";
    }
    std::cout << "------------------------------------\n";
    std::cout << "ÈÒÎÃÎ Ê ÎÏËÀÒÅ: " << totalSum << " ðóá.\n";
    std::cout << "====================================\n";
    Clear();
}

void Check::Clear() { products.clear(); }