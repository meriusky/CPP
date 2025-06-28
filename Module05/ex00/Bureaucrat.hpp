#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept> //o signal and handle runtime errors in a structured way

class Bureaucrat 
{
    private:
        const std::string name;
        int grade;

    public:
       Bureaucrat(const std::string& name, int grade);
        ~Bureaucrat();

        const std::string& getName() const;
        int getGrade() const;

        void incrementGrade(); // Raise grade (i.e., lower number)
        void decrementGrade(); // Lower grade (i.e., higher number)

        class GradeTooHighException : public std::exception
        {
            const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);//📌
//What is that?⤴️
  //This line declares an overload of the << operator for the 
  // Bureaucrat class. It allows you to use std::cout << b; 
  // (where b is a Bureaucrat object), and have it print something 
  // meaningful.

//std::ostream
  //This function returns a reference to an ostream (like std::cout), 
  //so it can be chained (std::cout << b << " done").

#endif
