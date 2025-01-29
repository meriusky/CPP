#include "Zombie.hpp"

Zombie* Zombie::newZombie(std::string name)
{//Like malloc but in c++, we're saving memory and creating a new zombie🧟
		Zombie *z = new Zombie(name);
		return z;
}
