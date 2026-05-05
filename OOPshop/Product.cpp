#include "Product.hpp"

Product::Product(unsigned int id, std::string name, double price, unsigned int count)
    : id(id), name(name), price(price), count(count) {
}

unsigned int Product::getId() const { return id; }
void Product::setId(unsigned int id) { this->id = id; }
std::string Product::getName() const { return name; }
void Product::setName(const std::string& name) { this->name = name; }
double Product::getPrice() const { return price; }
void Product::setPrice(double price) { this->price = price; }
unsigned int Product::getCount() const { return count; }
void Product::setCount(unsigned int count) { this->count = count; }