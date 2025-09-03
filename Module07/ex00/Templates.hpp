#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

// swap: exchange values of two parameters
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
    return (a < b ? a : b);
}

// max: return the greatest of two values
template <typename T>
T const &max(T const &a, T const &b)
{
    return (a > b ? a : b);
}

#endif

