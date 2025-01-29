#include "Zombie.hpp"

void Zombie::randomChump(std::string name)
{//Is makeing a new zombie with the same name
	Zombie z(name);
	z.announce();
}
