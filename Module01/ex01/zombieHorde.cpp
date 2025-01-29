#include "Zombie.hpp"

Zombie* Zombie::zombieHorde(int N, std::string name)
{
	Zombie* z = new Zombie [N];//*1
	for(N--; N >= 0; N--)//*2
		z[N].setName(name);//*3
	return z;
}
//1:dynamically allocates an array of N Zombie on the heap using new
//2:Before the loop starts ensures N is in a valid index. Each time
// :the code does the loop N--; till it'll reaches 0. Then we know all
// :the zombies have gone to setName.
//3:Each zombie is getting it name :)
//
