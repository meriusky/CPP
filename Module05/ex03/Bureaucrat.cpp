#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string& n, int g) : name(n), grade(g) 
{
    if (g < 1)
        throw GradeTooHighException();
    if (g > 150)
        throw GradeTooLowException();
    std::cout << "Bureaucrat " << name << " created with grade " << grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) 
{
    if (this != &other) 
	{
        this->grade = other.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() 
{
    std::cout << "Bureaucrat " << name << " destroyed" << std::endl;
}

const std::string& Bureaucrat::getName() const { return name; }
int Bureaucrat::getGrade() const { return grade; }

void Bureaucrat::incrementGrade() 
{
    if (grade - 1 < 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade() 
{
    if (grade + 1 > 150)
        throw GradeTooLowException();
    grade++;
}

void Bureaucrat::signForm(AForm& form) 
{
    try 
	{
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << name << " couldn’t sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm& form) 
{
    try 
	{
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    } 
	catch (std::exception& e) 
	{
        std::cout << name << " couldn’t execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() 
{
    return "Bureaucrat: grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() 
{
    return "Bureaucrat: grade too low!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) 
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}
