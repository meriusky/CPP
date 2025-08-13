#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name) 
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const 
{
    return name;
}

int Bureaucrat::getGrade() const 
{
    return grade;
}

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

const char* Bureaucrat::GradeTooHighException::what() const throw() 
{
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() 
{
    return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) 
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}
