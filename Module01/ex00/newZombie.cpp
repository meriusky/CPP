#include "Zombie.hpp"

Zombie* Zombie::newZombie(std::string name)
{//malloc version c++, estamos guardando memoria, creanod un zombie nuevo🧟
		Zombie *z = new Zombie(name);
		return z;
}
