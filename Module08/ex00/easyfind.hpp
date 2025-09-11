#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm> // std::find
#include <stdexcept> // std::runtime_error

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);

    if (it == container.end())//If std::find don't found the end
        throw std::runtime_error("Value not found in container");

    return it;
}

#endif
//We use typename to tell the compiler that what is has in front is a type (T::iterator)
//T::iterator is an iterator type to travell their elements (std::vector<int>::iterator, list deque)//Is generic, it will atomatically become the correct iterator type depending on the container T I pass to easyfind
//T& conteiner is reference to an existing container, I'M NOT CREATING THE CONTAINER, is created elsewhere(in the main :)
//See this expemple✏️
//(typename T::iterator) (easyfind) (T& container, int value)  This two
//            void function_name(int variable)                are the same
//
//Let's explain✏️
//typename T::iterator it = std::find(container.begin(), container.end(), value);
//⬆️         1️⃣          ⬆️   ⬆️   2️⃣   ⬆️  ⬆️                3️⃣                       ⬆️
//1️⃣ Declares the variable it whith this type
//2️⃣ algorith that searches a range of elemets
//3️⃣ iteretor pointing to the ferst last element value is the integer i want to find

