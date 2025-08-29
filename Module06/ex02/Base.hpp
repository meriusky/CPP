#ifndef BASE_HPP
#define BASE_HPP

class Base
{
public:
    virtual ~Base(); // must be virtual for dynamic_cast to work properly
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif

