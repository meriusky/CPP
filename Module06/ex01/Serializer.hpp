#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h> // for uintptr_t
#include "Data.hpp"

class Serializer
{
	private:
    // Private constructor/destructor to prevent instantiation:required by subject
   		Serializer();
    	~Serializer();
    	Serializer(const Serializer&);
    	Serializer& operator=(const Serializer&);

	public:
		//Takes a pointer to Data object and converts it into an unsigned integer uintptr_t
    	static uintptr_t serialize(Data* ptr);//required by subject
		//Take the integer and converts it back into the original pointer
    	static Data* deserialize(uintptr_t raw);//required by subject
};
#endif

//What is uintptr_t?
//Just a type, unsigned integer type, it comes from <cstdint>
//Raw ist just the name
