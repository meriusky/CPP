#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat; // Forward declaration to avoid circular include

class AForm 
{
	private:
	    const std::string name;
	    bool isSigned;
	    const int gradeToSign;
	    const int gradeToExecute;

	public:
	    // Constructors / Destructor
	    AForm(const std::string& n, int signGrade, int execGrade);
	    AForm(const AForm& other);
	    AForm& operator=(const AForm& other);
	    virtual ~AForm();

    	// Getters
	    std::string getName() const;
	   	bool getIsSigned() const;
	    int getGradeToSign() const;
	    int getGradeToExecute() const;

    	// Methods
    	void beSigned(const Bureaucrat& b);

	    // Pure virtual function (makes class abstract)
	    virtual void execute(const Bureaucrat& executor) const = 0;

	    // Exceptions
	    class GradeTooHighException : public std::exception 
		{
		    public:
			const char* what() const throw();
	    };

	    class GradeTooLowException : public std::exception 
		{
		    public:
 	       const char* what() const throw();
	    };

    class FormNotSignedException : public std::exception 
	{
	    public:
	        const char* what() const throw();
    };
};

// Operator overload for printing form info
std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
