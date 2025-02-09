#include "ScavTrap.hpp"

// Constructor
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " has been created!" << std::endl;
}

// Copy Constructor
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    *this = other;
    std::cout << "ScavTrap " << _name << " has been copied!" << std::endl;
}

// Copy Assignment Operator
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other) 
        ClapTrap::operator=(other);
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " has been destroyed!" << std::endl;
}

//attack function
void ScavTrap::attack(const std::string& target)
{
    if (_hitPoints <= 0 || _energyPoints <= 0)
	{
        std::cout << "ScavTrap " << _name << " has no energy or hit points left to attack!" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "ScavTrap " << _name << " viciously attacks " << target 
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

// Guard Gate mode function
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode!" << std::endl;
}

