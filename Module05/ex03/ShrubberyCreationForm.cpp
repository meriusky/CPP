#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& t)
    : AForm("ShrubberyCreationForm", 145, 137), target(t) {}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target) {}

// Assignment operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) 
{
    if (this != &other) 
	{
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Execute method
void ShrubberyCreationForm::execute(const Bureaucrat& executor) const 
{
    // Check that the form is signed
    if (!getIsSigned())
        throw FormNotSignedException();

    // Check if executor is high enough to execute
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    // Create output file
    std::ofstream ofs((target + "_shrubbery").c_str());//📍
    if (!ofs)//check is the file is succeesfully open if not prints an error
	{
        std::cerr << "Error: Could not open file " << target + "_shrubbery" << std::endl;
        return;
    }

    ofs << "       ###\n";
    ofs << "      #o###\n";
    ofs << "    #####o###\n";
    ofs << "   #o#\\#|#/###\n"; //this works like std::cout but writes on a file.
    ofs << "    ###\\|/#o#\n";  // ofs is std::ofstream
    ofs << "     # }|{  #\n";
    ofs << "       }|{\n";

    ofs.close();//close the file
    std::cout << "ShrubberyCreationForm executed: " << target + "_shrubbery created." << std::endl;
}
//📍std::ofstream is like std::cout but writes to a file instead of console. In this case writes to the tree to the file :)
//ofs is the variable name of this stream, I could nameit anything but usually stands for "output files stream"
//(target + "_shrubbery").c_str() builds the filename for the tree
