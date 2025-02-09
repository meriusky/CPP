#include "Dog.hpp"
#include "Cat.hpp"

int main() 
{
    const int animalCount = 4;
    AAnimal* animals[animalCount];

    // Creating animals: first half Dogs, second half Cats
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
// revisar este ejercicio
// Question: What does it mean that class a should not be instantiable?
// Answer: it means that you should not be able to create an object of AAnimal. This is because AAnimal is meant to serve as a base class for Cat and Dog, but it does not represent a specific animal itself.
