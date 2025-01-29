#include "Zombie.hpp"

int main()
{
	Zombie Valerio(std::string("Valerio"));
	Zombie Paula(std::string("Paula"));
	Zombie Oliver(std::string("Oliver"));
	Zombie* Meritxell;
	
	Valerio.announce();
	Meritxell = Paula.newZombie(std::string("Meritxell"));
	Meritxell->announce();
	delete Meritxell;
	Oliver.randomChump(std::string("Oliver"));
	return(0);
}
