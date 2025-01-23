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
/*
Zombie* Zombie::newZombie(std::string name)
{//malloc version c++, estamos guardando memoria, creanod un zombie nuevo🧟
		Zombie *z = new Zombie(name);
		return z;
}

void Zombie::randomChump(std::string name)
{
	Zombie z(name);
	z.announce();
}*/
