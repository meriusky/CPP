#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
    FragTrap frag("Fraggy");
    
    frag.attack("Enemy");
    frag.takeDamage(30);
    frag.beRepaired(20);
    frag.highFivesGuys();

    return 0;
}

