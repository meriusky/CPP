#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() 
{
    std::cout << "---- Testing Normal Animals ----" << std::endl;
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();

    std::cout << animal1->getType() << " says: ";
    animal1->makeSound();

    std::cout << animal2->getType() << " says: ";
    animal2->makeSound();

    delete animal1;
    delete animal2;

    std::cout << "\n---- Testing Wrong Animals ----" << std::endl;
    WrongAnimal* wrongAnimal = new WrongCat();

    std::cout << wrongAnimal->getType() << " says: ";
    wrongAnimal->makeSound();  // Will call WrongAnimal::makeSound() because it's not virtual

    delete wrongAnimal;

    return 0;
}
/*
int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	return 0;
}*/

