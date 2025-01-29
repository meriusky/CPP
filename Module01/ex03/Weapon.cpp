#include "Weapon.hpp"

Weapon::Weapon() : _type("") {}
Weapon::Weapon(const char* type)
{
    _type = type;
	std::cout << "constructor weapon" << std::endl;
}
Weapon::~Weapon()
{
	std::cout << _type << " destroyed, human is screwed💀" << std::endl;
}

const std::string& Weapon::getType() const
{
    return _type;
}
void Weapon::setType(std::string str)
{
    _type = str;
}
