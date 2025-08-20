#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool    isSigned;
        const int gradeToSign;
        const int gradeToExecute;

    public:
        Form(const std::string& name, int gradeToSing, int gradeToExecute);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        //Getters (required on subject)
        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(const Bureaucrat& b);
//Subject sais "If grade is too low or hight, trow a Form::GradeTooLowException" if it has to be like this,
// GradeTooLowException has to be a class in Form🫡
        class GradeTooHighException : public std::exception 
        {
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception 
        {
            const char* what() const throw();
        };
    
};
//operator overload 😉
    std::ostream& operator<<(std::ostream& os, const Form& f);

#endif