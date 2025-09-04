#include "Intern.hpp"

Intern::Intern() {}//constructor
Intern::Intern(const Intern& other) { (void)other; }//copoy constructor
//Assignment Operator: return *this and (void)other silences unused parameter warnings
Intern& Intern::operator=(const Intern& other) { (void)other; return *this; }
Intern::~Intern() {}//destructor

// Static helper creators to create forms:
// they don’t need access to any Intern object; they just return new forms.
static AForm* createShrubbery(const std::string& target)
{
	//target is the name or location the form will act on
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target) 
{
    return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string& target) 
{
    return new PresidentialPardonForm(target);
}

//The makeForm funcion👇
AForm* Intern::makeForm(const std::string& formName, const std::string& target) 
{
	//Holds all the valid form names the Intern can create.
    const std::string names[] = //array😊
	{
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
//Holds pointers to the statis function that actually create each form
    AForm* (*creators[])(const std::string&) = //an array of function pointers taking const::std
	{                                         //and return ning AForm*
        &createShrubbery,
        &createRobotomy,
        &createPresidential
    };
//loop through the names
    for (int i = 0; i < 3; i++) 
	{
        if (formName == names[i]) //Compares the input forName with each valid name
		{                         //if it match Inter creates <forName> and calls corresponding function
            std::cout << "Intern creates " << formName << std::endl;
            return creators[i](target);
        }
    }
//if not match, it sais so
    std::cout << "Intern couldn’t find form \"" << formName << "\"" << std::endl;
    return NULL;
}


