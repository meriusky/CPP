#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string type;
	
	public:
	    Animal();
	    Animal(const Animal& other);
	    Animal& operator=(const Animal& other);
	    virtual ~Animal();//*1

	    virtual void makeSound() const; //*2
	    std::string getType() const; 
};
#endif
/*1:
 * A virtual destructor ensures that when an object is deleted through a pointer
 *  to the base class, the correct derived class destructor is called
 *  first, preventing memory leaks.
 * 2:
 * Declaring methods as virtual allows dynamic polymorphism, meaning derived classes
 * can override it and the correct version will be called at runtime*/
