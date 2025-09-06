#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>   //For std::string (the input literal)
#include <iostream> //std::cout. std::cerr (printing results)
#include <limits>   //For numeric limits
#include <cstdlib>  //For std::strtod, std::strtol, std::atof, std::atoi
#include <cerrno>   //errno, to detect coversion errors
#include <climits>  //For constants like INT_MAX, INT_MIN
#include <cfloat>   //For dloat and double limits 	FLT_MAX or DBL_MAX
#include <cmath>    //For isnan(), isinf() checks

class ScalarConverter 
{
	private:
    	ScalarConverter(); // not instantiable
    	ScalarConverter(const ScalarConverter&);
    	ScalarConverter& operator=(const ScalarConverter&);

	public:
    	static void convert(const std::string& literal);//static bc we don't need objects from it
};
#endif
//Non instantiable?
//The constructor, copy constructor and assigments operator are 
//private(or protected) and not implemented. This make the class non-instantiable.
//You cannot creat objects of the class directly.
//
//Thats supper in this case cause we are taking the information from
//the prompt so we use the class as a tool not as a thing. Instead of
//declaring again and again we just take the promp and do something with it.

