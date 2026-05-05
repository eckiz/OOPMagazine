#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>

class Product {
private:
    unsigned int id;
    std::string name;
    double price;
    unsigned int count;

public:
    Product(unsigned int id, std::string name, double price, unsigned int count);

    // Геттеры и сеттеры согласно схеме
    void setID(unsigned int id);
    unsigned int getID() const;
    void setName(std::string name);
    std::string getName() const;
    void setPrice(double price);
    double getPrice() const;
    void setCount(unsigned int count);
    unsigned int getCount() const;
};

#endif