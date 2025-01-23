#include "Zombie.hpp"

int main()
{
	Zombie Josep(std::string("Josep"));
	Zombie Toallas(std::string("Toallas"));
	Zombie Faixa(std::string("Faixa"));
	Zombie* MissFortune;
	
	Josep.announce();
	MissFortune = Toallas.newZombie(std::string("MissFortune"));
	MissFortune->announce();
	delete MissFortune;
	Faixa.randomChump(std::string("Patatin"));
	return(0);
}
