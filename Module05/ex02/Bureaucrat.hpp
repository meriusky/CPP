#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class AForm; // Forward declaration

class Bureaucrat 
{
	private:
	    const std::string name;
	    int grade;

	public:
	    Bureaucrat(const std::string& n, int g);
	    Bureaucrat(const Bureaucrat& other);
	    Bureaucrat& operator=(const Bureaucrat& other);
	    ~Bureaucrat();

	    const std::string& getName() const;
	    int getGrade() const;

	    void incrementGrade();
	    void decrementGrade();

	    void signForm(AForm& form);
	    void executeForm(const AForm& form);

	    class GradeTooHighException : public std::exception 
		{
	        const char* what() const throw();
 	    };

	    class GradeTooLowException : public std::exception 
		{
	        const char* what() const throw();
	    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
