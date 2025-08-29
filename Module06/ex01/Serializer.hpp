#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h> // for uintptr_t
#include "Data.hpp"

class Serializer
{
private:
    // Private constructor/destructor to prevent instantiation
    Serializer();
    ~Serializer();
    Serializer(const Serializer&);
    Serializer& operator=(const Serializer&);

public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif

