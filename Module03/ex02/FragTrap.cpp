#include "FragTrap.hpp"
#include <iostream>

// Constructor
FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " has been constructed!" << std::endl;
}

// Copy Constructor
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap copy constructor called!" << std::endl;
}

// Copy Assignment Operator
FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << "FragTrap assignment operator called!" << std::endl;
    return *this;
}

// Destructor
FragTrap::~FragTrap() {
    std::cout << "FragTrap " << _name << " has been destroyed!" << std::endl;
}

// Special Function
void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << _name << " is asking for a HIGH FIVE! ✋" << std::endl;
}

