#include <iostream>   //For input/output
#include <vector>     // For standard conteiners I want to test
#include <list>       // "          "          "             "
#include "easyfind.hpp"

int main()
{
//I create a vector of integers named v
    std::vector<int> v;
    v.push_back(10); //we add the elements using push_back
    v.push_back(20);
    v.push_back(30);

//Print all elements of the vector
    std::cout << "Vector elements: ";
//Iteration from the begining (v.begin) to the end (v.end) with *it to get value
	std::vector<int>::iterator it = v.begin();
	while(it != v.end())
	{
        std::cout << *it << " ";
		it++;
	}
    std::cout << std::endl;

//For safety: if easyfind doesen't find elemet,it throw exception
    try 
	{
        std::vector<int>::iterator found = easyfind(v, 20);
        std::cout << "Found: " << *found << std::endl;
    } 
	catch (const std::exception &e) 
	{
        std::cout << e.what() << std::endl;
    }

    return 0;
}

//GOAL: Write a function template that can search for an integer inside any STL container
//
//What is STL container: Standard Template Library Container
//Container: Is a C++ class template that stores collection of objects in memory, giving you ways to organize, access and manipulate data. Like a smart box where I can put the data and later retrieve, search and modify it efficiently.
//
//We have several types of STL containers: each optimized for different use cases.
//SEQUENCE CONTAINER-> Order like an array or list (std::vector, std::deque, std::list)
//ASSOCIATIVE CONTAINER->Stored dataa, implemented as trees (std::set, ::multiset, ::map,::multimap)
//UNORDERED CONTAINERS-> Hash tables and faster lookups (std::unordered_set, std::unordered_map)
//
//
