#include "Weapon.hpp"

Weapon::Weapon() : _type("") {}
Weapon::Weapon(const char* type)
{
    _type = type;
}
Weapon::~Weapon()
{
	std::cout << _type << " destroyed, human is screwed😰" << std::endl;
}

const std::string& Weapon::getType() const
{
    // std::string& weaponType = type; //reference
//    weaponType.setType
    // return weaponType;
    return _type;
}
void Weapon::setType(std::string str)
{
    _type = str;
//    std::cout << "the weapon is a: " << str << std::ednl;
}
