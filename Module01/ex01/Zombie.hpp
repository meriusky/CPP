#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <iostream>

class Zombie
{
	private:
		std::string _name;
	public:
		Zombie();
		Zombie(std::string);
		~Zombie();
		Zombie* zombieHorde(int N, std::string name);
		void	setName(std::string name);
		void	announce(void);
};
#endif
