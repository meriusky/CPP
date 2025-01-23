#include "Zombie.hpp"

Zombie* Zombie::zombieHorde(int N, std::string name)
{
	Zombie* z = new Zombie [N];
	for(N--; N >= 0; N--)
		z[N].setName(name);
	return z;
}
