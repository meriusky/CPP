#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap claptrap("Clappy");
    ScavTrap scavtrap("Scavvy");

    claptrap.attack("Enemy1");
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);

    scavtrap.attack("Enemy2");
    scavtrap.takeDamage(40);
    scavtrap.beRepaired(20);
    scavtrap.guardGate();

    return 0;
}

