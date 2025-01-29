#include "Zombie.hpp"

int main()
{
	int N = 5;
	int i = 0;

	Zombie Josep(std::string("Josep"));
	Zombie* show = Josep.zombieHorde(N, "Pep");


	while(i != N)
	{
		show[i].announce();
		i++;
	}
	return(0);
}
