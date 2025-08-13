#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureacrat;

class Form
{
    private:
        const std::string name;
        bool sign;
        const int gradeToSign;
        const int gradeToExecute;

    public:
        Form(const std::string& name, int gradeToSing, int gradeToExecute);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        //Getters (required on subject)
        std::string getName() const;
        bool getSign() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(const Bureacrat& b);

        class GradeTooHighException : public std::exception 
        {
            const char* what() const trhow();
        };
        class GradeTooLowException : public std::exception 
        {
            const char* what() const trhow();
        };
    
}
//operator overload 😉
    std::ostream& operator<<(std::ostream& os, const Form& f);

#endif