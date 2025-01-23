#include "Zombie.hpp"

Zombie::Zombie(){}
Zombie::Zombie(std::string name) : _name(name) {}

Zombie::~Zombie()
{
	std::cout << std::string(_name) << "Zombie destroyed🧠. Good bye🧟" << std::endl;
}
void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	_name = name;
}
