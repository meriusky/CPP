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

// #ifndef BUREAUCRAT_HPP
// #define BUREAUCRAT_HPP

// #include <iostream>
// #include <stdexcept> //To signal and handle runtime errors in a structured way
// #include "Form.hpp"
// class Form;   // forward declaration

// class Bureaucrat 
// {
//     private:
//         const std::string name;
//         int grade;

//     public:
//        Bureaucrat(const std::string& name, int grade);
//         ~Bureaucrat();

//         const std::string& getName() const;
//         int getGrade() const;

//         void incrementGrade(); // Raise grade (i.e., lower number)
//         void decrementGrade(); // Lower grade (i.e., higher number)
//         void signForm(Form& form); // For signing
//         void executeForm(const AForm& form) const;// For 


//         class GradeTooHighException : public std::exception
//         {
//             const char* what() const throw();
//         };

//         class GradeTooLowException : public std::exception
//         {
//             const char* what() const throw();
//         };

// };

// std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);//📌
// //What is that?⤴️
//   //This line declares an overload of the << operator so I can
//   // print a "Bureaucrat" with std::cout, Without manually calling getter.

// //std::ostream
//   //This returns a type, the same output I pass in (like std::cout), 
//   //so it can be chained (std::cout << b << " done").
// //operator<<
//   //This is the function name, the << (insertion operator) is being 
//   //overloaded to work with your custom class
// //(std::ostream& os, const Bureaucrat& b)
//  //These are the parameters, the first one is a reference to the output
//  // stream (std::) so the fuction can write. The second is the constant
//  //reference to the object so it can be printed.

// //In conclusion if that line wasn't there you would have to write 
// // std::cout << b.getname() << ",grade " << b.getGrade() << std::endl;
// // now with the operator you just call teh fuction that is in the .cpp
// // and it does everithing.

// #endif
