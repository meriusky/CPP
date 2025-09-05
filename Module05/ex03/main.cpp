#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() 
{
    Intern randomIntern;
    AForm* form;

    form = randomIntern.makeForm("robotomy request", "Bender");//is it match return pointer to a new 
	if (form)											   //RobotomyRequestForm("Bender") if not returnNULL
	{
        Bureaucrat john("John", 40);//create Bureaucrat John
        john.signForm(*form);//John tries to sign and should succeed
        john.executeForm(*form);//John tries to execute
        delete form;//delete to free memory bc makeForm allocated it with new
    }

    form = randomIntern.makeForm("shrubbery creation", "Home");
    if (form) 
	{
        Bureaucrat mike("Mike", 140);
        mike.signForm(*form);
        mike.executeForm(*form);
        delete form;
    }

    form = randomIntern.makeForm("invalid form", "Nobody"); // Should fail bc intern doesen't recognize
    delete form; // NULL is safe to delete

    return 0;
}

