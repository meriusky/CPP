#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef> // for size_t

template <typename T>
void iter(T* array, size_t length, void (*func)(T&))
{
    if (!array || !func)//safety check, to prevent crashes
        return;
    for (size_t i = 0; i < length; ++i)//loop through each element
        func(array[i]);// calls function on each element
}

#endif
//Function template iter: 
// 1.The array(as a pointer to the first element)
// 2.The length of the array
// 3.A function that wi be applied to each elemt of the array
//
//T is a template parameter so this function can work with any type
//Parameters:
// 1.T* array➡️ A pointer to the first elemet of an array of type T
// 2.size_t lenght➡️ Number of elements in the array
// 3.void (*func)(T&)➡️ Function pointer that takes a reference t T and returns void
