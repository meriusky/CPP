#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap 
{
	protected: //*1
	    std::string _name;
	    int _hitPoints;
	    int _energyPoints;
	    int _attackDamage;

	public:
	    ClapTrap(const std::string& name);
	    ClapTrap(const ClapTrap& other);
	    ClapTrap& operator=(const ClapTrap& other);
	    virtual ~ClapTrap();  // Virtual destructor for proper polymorphic behavior

	    virtual void attack(const std::string& target);
	   	void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};
#endif
/* Protected enstead of private?
Private:
	Accessible only inside the class that defines it.
	Not accessible in derived (child) classes.
Protected
    Accessible inside the class that defines it.
    Also accessible in derived (child) classes, but not outside them.

Use private if you don't want derived classes to access or modify the 
data directly. Use protected if you want derived classes to be able to
use the data but still prevent outside access.*/

