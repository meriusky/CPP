#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
    std::cout << "ClapTrap " << _name << " has been created!" << std::endl;
}

// Copy Constructor
ClapTrap::ClapTrap(const ClapTrap& other)
{
    *this = other;
    std::cout << "ClapTrap " << _name << " has been copied!" << std::endl;
}

// Copy Assignment Operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other) 
{
    if (this != &other) 
	{
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() 
{
    std::cout << "ClapTrap " << _name << " has been destroyed!" << std::endl;
}

// Attack function
void ClapTrap::attack(const std::string& target) 
{
    if (_hitPoints <= 0 || _energyPoints <= 0) 
	{
        std::cout << "ClapTrap " << _name << " has no energy or hit points left to attack!" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " attacks " << target 
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

// Take damage function
void ClapTrap::takeDamage(unsigned int amount) 
{
    _hitPoints -= amount;
    if (_hitPoints < 0) _hitPoints = 0;
    std::cout << "ClapTrap " << _name << " takes " << amount 
              << " damage! Remaining HP: " << _hitPoints << std::endl;
}

// Repair function
void ClapTrap::beRepaired(unsigned int amount) 
{
    if (_hitPoints <= 0 || _energyPoints <= 0) 
	{
        std::cout << "ClapTrap " << _name << " has no energy or hit points left to repair!" << std::endl;
        return;
    }
    _energyPoints--;
    _hitPoints += amount;
    std::cout << "ClapTrap " << _name << " repairs itself for " << amount 
              << " HP! Current HP: " << _hitPoints << std::endl;
}

