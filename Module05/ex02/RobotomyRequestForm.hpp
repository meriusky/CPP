#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>  // for rand()
#include <ctime>    // for srand()

class RobotomyRequestForm : public AForm 
{
	private:
 	   std::string target;

	public:
	    RobotomyRequestForm(const std::string& target);
	    RobotomyRequestForm(const RobotomyRequestForm& other);
	    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	    ~RobotomyRequestForm();

	    // Override execute
	    void execute(const Bureaucrat& executor) const;
};

#endif
