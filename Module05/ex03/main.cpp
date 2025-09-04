#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() 
{
    Intern someRandomIntern;
    AForm* form;

    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form) 
	{
        Bureaucrat john("John", 40);
        john.signForm(*form);
        john.executeForm(*form);
        delete form;
    }

    form = someRandomIntern.makeForm("shrubbery creation", "Home");
    if (form) 
	{
        Bureaucrat mike("Mike", 140);
        mike.signForm(*form);
        mike.executeForm(*form);
        delete form;
    }

    form = someRandomIntern.makeForm("invalid form", "Nobody"); // Will fail
    delete form; // NULL is safe to delete

    return 0;
}

