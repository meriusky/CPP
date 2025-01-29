#ifndef HUMANB_HPP
# define HUMANB_HPP
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
    private:
        Weapon* _weapon;
        std::string _name;

    public:
        HumanB(std::string);
        ~HumanB();
        void attack();
        void setWeapon(Weapon&);

};
#endif
