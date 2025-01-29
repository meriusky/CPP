#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    _name = name;
	_weapon = NULL;
	std::cout << "constructor HumanB" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "Weapon from HumanB is destroyed😰" << std::endl;
}

void HumanB::attack()
{
    if(_weapon == NULL)
        std::cout << _name << " does not have a weapon😰" << std::endl;
    else
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
void HumanB::setWeapon(Weapon& weapon)
{
     _weapon = &weapon;
	std::cout << "weapon for B seted" << std::endl;
}
