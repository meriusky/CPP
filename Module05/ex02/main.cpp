#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() 
{
    try 
	{
        Bureaucrat andrei("Andrei", 1);    // Top rank bureaucrat
        Bureaucrat paula("Paula", 140);      // Lower rank bureaucrat
        Bureaucrat meritxell("Meritxell", 50);

        std::cout << "=== Creating Forms ===" << std::endl;
        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Marvin");
        PresidentialPardonForm pardon("Ford Prefect");

        std::cout << std::endl << "=== Trying to sign forms ===" << std::endl;
		andrei.signForm(shrub);   // Should succeed
	 	andrei.signForm(pardon);  // Should succeed
	  	andrei.signForm(robot);   // Should succeed
								  
		paula.signForm(shrub);   // Should succeed 
	 	paula.signForm(pardon);  // Should fail
	  	paula.signForm(robot);   // Should fail

		meritxell.signForm(shrub);   // Should succeed
	 	meritxell.signForm(pardon);  // Should fail
	  	meritxell.signForm(robot);   // Should succeed

        std::cout << std::endl << "=== Trying to execute forms ===" << std::endl;
		andrei.executeForm(shrub);//Should succeed
		andrei.executeForm(robot);//Should succeed
		andrei.executeForm(pardon); //Should succedd
									//
		paula.executeForm(shrub); //Should fail 
		paula.executeForm(robot); //Should fail
		paula.executeForm(pardon); //Should fail
								   
		meritxell.executeForm(shrub); //Should succeed
		meritxell.executeForm(robot); //Should succeed or fail randomly
		meritxell.executeForm(pardon); //should fail
    } 
	catch (std::exception& e) 
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
