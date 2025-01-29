#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon)
{
    _name = name;
    _weapon = weapon;
	std::cout << "constructor Human A" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "Weapon from HumanA is destroyed😰" << std::endl;
}

void HumanA::attack()
{
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
