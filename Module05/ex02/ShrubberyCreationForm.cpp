#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

// Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& t)
    : AForm("ShrubberyCreationForm", 145, 137), target(t) {}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target) {}

// Assignment operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Execute method
void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    // Check that the form is signed
    if (!getIsSigned())
        throw FormNotSignedException();

    // Check if executor has permission
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    // Create output file
    std::ofstream ofs((target + "_shrubbery").c_str());
    if (!ofs) {
        std::cerr << "Error: Could not open file " << target + "_shrubbery" << std::endl;
        return;
    }

    // Write ASCII tree into the file
    ofs << "       ###\n";
    ofs << "      #o###\n";
    ofs << "    #####o###\n";
    ofs << "   #o#\\#|#/###\n";
    ofs << "    ###\\|/#o#\n";
    ofs << "     # }|{  #\n";
    ofs << "       }|{\n";

    ofs.close();
    std::cout << "ShrubberyCreationForm executed: " << target + "_shrubbery created." << std::endl;
}
// #include "ShrubberyCreationForm.hpp"
// #include <iostream>

// // Constructor: sets required sign/execution grades (145, 137)
// ShrubberyCreationForm::ShrubberyCreationForm(const std::string& t)
//     : AForm("ShrubberyCreationForm", 145, 137), target(t) {}

// ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
//     : AForm(other), target(other.target) {}

// ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
//     if (this != &other) {
//         AForm::operator=(other);
//         target = other.target;
//     }
//     return *this;
// }

// ShrubberyCreationForm::~ShrubberyCreationForm() {}

// void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
//     // Check inherited rules: signed? executor grade ok?
//     checkExecutable(executor);

//     // Create a file with ASCII trees
//     std::ofstream file(target + "_shrubbery");
//     if (!file) {
//         std::cerr << "Error: could not open file " << target + "_shrubbery" << std::endl;
//         return;
//     }

//     file << "       _-_\n"
//             "    /~~   ~~\\\n"
//             " /~~         ~~\\\n"
//             "{               }\n"
//             " \\  _-     -_  /\n"
//             "   ~  \\\\ //  ~\n"
//             "_- -   | | _- _\n"
//             "  _ -  | |   -_\n"
//             "      // \\\\\n";

//     file.close();

//     std::cout << "ShrubberyCreationForm: created " << target << "_shrubbery file 🌳" << std::endl;
// }
