#ifndef SADMIN
#define SADMIN

#include "Admin.hpp"

class SuperAdmin : public Admin {
public:
    SuperAdmin(std::string l, std::string p, unsigned int i, Official* off);
    void ShowMenu() override;
};
#endif