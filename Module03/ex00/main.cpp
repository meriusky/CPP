#include "ClapTrap.hpp"

int main() 
{
    ClapTrap claptrap("Clappy");

    claptrap.attack("Enemy1");
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);
    claptrap.attack("Enemy2");
    claptrap.takeDamage(10);
    claptrap.beRepaired(5);  // Should fail since HP is 0

    return 0;
}

