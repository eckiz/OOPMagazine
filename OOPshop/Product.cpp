#include "Product.hpp"

Product::Product(unsigned int id, std::string name, double price, unsigned int count)
    : id(id), name(name), price(price), count(count) {
}

void Product::setID(unsigned int id) { this->id = id; }
unsigned int Product::getID() const { return id; }

void Product::setName(std::string name) { this->name = name; }
std::string Product::getName() const { return name; }

void Product::setPrice(double price) { this->price = price; }
double Product::getPrice() const { return price; }

void Product::setCount(unsigned int count) { this->count = count; }
unsigned int Product::getCount() const { return count; }