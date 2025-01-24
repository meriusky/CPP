#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    _name = name;
}

HumanB::~HumanB()
{
	std::cout << "Weapon from HumanA is destroyed😰" << std::endl;
}

void HumanB::attack()
{
    if(_weapon == NULL)
        std::cout << _name << " does not have a weapon😰" << std::endl;
    else
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
void HumanB::setWeapon(Weapon weapon)
{
    _weapon = &weapon;
//  std::cout << _name << " has set this weapon: " << _weapon->getType() << std::endl;
}