#ifndef BASE_HPP
#define BASE_HPP

//Just one important feature: a virtual destructor that makes the class plymorphic
//that is required for the dynamic_cast to work.
class Base
{
	public:
    	virtual ~Base(); // must be virtual for dynamic_cast to work properly
};
//derived from Base, they are empty bc their only job is to be different types for meto distinguish at runtime.
class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif
//REMEMBER💡: POLYMORPHIC
//It literaly means "many forms" and it allows objects of different derived classes 
//to be treated as objects of the base class, but still retain their actual behavior.
//dynamic_cast is a C++ operator used with polymorphic types to safely convert a
//pointer or reference of a base class type into a derived class type.
