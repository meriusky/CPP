#ifndef WHATEVER_HPP
#define WHATEVER_HPP

// swap: swaps values of two variables
template <typename T>
void swap(T &a, T &b)
{
    T temp = a;              
    a = b;
    b = temp;
}

// min: return the smallest of two values
template <typename T>
T const &min(T const &a, T const &b)   
{
	if (a < b)
		return a;
	else
		return b;
}

// max: return the larger of two values
template <typename T>
T const &max(T const &a, T const &b)
{
	if (a > b)
		return a;
	else
		return b;
}

#endif
//Function templates: Basically fuctions that work with any type without rewriting them
//
//template <typename T> ➡️ Makes the function generetic, T is just de placeholder
//
//swap➡️  Uses & so that the function modifies the actual variable
//    ➡️  Creates a temporary copy to hold one value during te swap
//
//min ➡️ Takes two const references (no cpying and prevents modification)
//    ➡️ Uses < operator to compare, return a referene to the smaller one
//
//max ➡️ The same as min but with >
//
//return (a > b ? a : b) its a shorthand dor an if else
//
