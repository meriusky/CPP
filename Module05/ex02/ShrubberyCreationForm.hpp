#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm 
{
	private:
    	std::string target;

	public:
	    ShrubberyCreationForm(const std::string& target);
	    ShrubberyCreationForm(const ShrubberyCreationForm& other);
	    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	    ~ShrubberyCreationForm();

    // Override execute method
	    void execute(const Bureaucrat& executor) const;
};

#endif
// #pragma once
// #include "AForm.hpp"
// #include <fstream>

// class ShrubberyCreationForm : public AForm 
// {
// private:
//     std::string target;

// public:
//     ShrubberyCreationForm(const std::string& target);
//     ShrubberyCreationForm(const ShrubberyCreationForm& other);
//     ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
//     ~ShrubberyCreationForm();

//     void execute(Bureaucrat const & executor) const;
// };

