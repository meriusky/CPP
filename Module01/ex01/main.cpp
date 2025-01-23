#include "Zombie.hpp"

int main()
{
	int N = 5;
	int i = 0;

	Zombie Josep(std::string("Josep"));
	Zombie* show = Josep.zombieHorde(N, "JoseFina");


//	Zombie Toallas(std::string("Toallas"));
//	Zombie Faixa(std::string("Faixa"));
	while(i != N)
	{
		show[i].announce();
		i++;
	}
//	Josep.announce();
//	MissFortune = Toallas.newZombie(std::string("MissFortune"));
//	MissFortune->announce();
//	delete MissFortune;
//	Faixa.randomChump(std::string("Patatin"));
	return(0);
}
