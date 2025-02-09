#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap 
{
	protected:
	    std::string _name;
	    int _hitPoints;
	    int _energyPoints;
	    int _attackDamage;

	public:
	    ClapTrap(const std::string& name);
	    ClapTrap(const ClapTrap& other);
	    ClapTrap& operator=(const ClapTrap& other);
	    virtual ~ClapTrap();  //*1 Virtual destructor for proper polymorphic behavior

	    virtual void attack(const std::string& target); //*2
	    void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
/*1:
 * A virtual destructor ensures that when an object is deleted through a pointer
 *  to the base class (ClapTrap*), the correct derived class destructor is called
 *  first, preventing memory leaks.
 * 2:
 * Declaring attack as virtual allows dynamic polymorphism, meaning derived classes
 * can override it and the correct version will be called at runtime*/
