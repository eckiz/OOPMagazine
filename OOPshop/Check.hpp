#ifndef CHECK_HPP
#define CHECK_HPP

#include <vector>
#include "Product.hpp"

class Check {
private:
    std::vector<Product> products;

public:
    void CheckPushBack(const Product& p);
    void PrintCheck(double totalSum);
};

#endif