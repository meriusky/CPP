#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
//How are converting the pointer to integer and back?
//reinterpret_cast(thes is a cast operato) tells the compiles to treat the Data* as if was an integer.
//It doesen't move or copy it just reinterprets the address
