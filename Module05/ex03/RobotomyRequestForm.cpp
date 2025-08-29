#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string& t)
    : AForm("RobotomyRequestForm", 72, 45), target(t) {
    std::srand(std::time(NULL)); // Seed random generator once
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target(other.target) {}

// Assignment operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {}

// Execute
void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    // Check preconditions
    if (!getIsSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::cout << "BZZZZZZZ... drilling noises..." << std::endl;

    // 50% chance success
    if (std::rand() % 2 == 0)
        std::cout << target << " has been robotomized successfully 🤖✅" << std::endl;
    else
        std::cout << "Robotomy failed on " << target << " ❌" << std::endl;
}
