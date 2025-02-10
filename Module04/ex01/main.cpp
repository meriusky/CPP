#include "Dog.hpp"
#include "Cat.hpp"

int main() 
{
    const int animalCount = 4;
    Animal* animals[animalCount];

    // Creating animals
    for (int i = 0; i < animalCount / 2; i++)
        animals[i] = new Dog();
    for (int i = animalCount / 2; i < animalCount; i++)
        animals[i] = new Cat();

    // Making animals make sounds
    for (int i = 0; i < animalCount; i++)
        animals[i]->makeSound();

    // Deleting animals to test proper destructor calls and avoid memory leaks
    for (int i = 0; i < animalCount; i++)
        delete animals[i];

    return 0;
}
/*
int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
//	Dog basic;
//	{
//		Dog tmp = basic;
//	}
	delete j;//should not create a leak
	delete i;
	return 0;
}*/
