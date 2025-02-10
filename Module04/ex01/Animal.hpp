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
	   virtual ~Animal();

 	   virtual void makeSound() const; //What if it wasn't virtual?
 	   std::string getType() const;
};
#endif
// If makeSound() is not declared as virtual in the Animal class,
// polymorphism will not work properly. This means that when calling 
// makeSound() on a pointer or reference to Animal, it will always
// execute the Animal version of makeSound(), even if the object is
// actually a Dog or Cat.
