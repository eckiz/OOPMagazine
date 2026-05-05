#ifndef PRODUCT
#define PRODUCT
#include <string>

class Product {
private:
    unsigned int id;
    std::string name;
    double price;
    unsigned int count;
public:
    Product(unsigned int id, std::string name, double price, unsigned int count);

    unsigned int getId() const;
    void setId(unsigned int id);

    std::string getName() const;
    void setName(const std::string& name);

    double getPrice() const;
    void setPrice(double price);

    unsigned int getCount() const;
    void setCount(unsigned int count);
};
#endif  