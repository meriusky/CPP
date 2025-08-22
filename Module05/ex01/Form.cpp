#include "Form.hpp"
#include "Bureaucrat.hpp"

//constructor👇    👇values needed, 👇that we pass in 👇the main, they DON'T COME FROM THE CLASS, they're temporary, they only exsist in the constructor.         
Form::Form(const std::string& n, int signGrade, int execGrade)
    : name(n), isSigned(false), gradeToSign(signGrade), gradeToExecute(execGrade) 
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
    std::cout << "Form " << name << " created" << std::endl;
}
//We initializes all the variables, is Signed is false so is 0 (by default)
//for the last two we set required grades

//Copy Constructor👇: allows to creat a new Form from an existing one
Form::Form(const Form& other)
    : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) 
{}
//📍Why do I need one?
//C++ will generate a default one for you, but since the class has conts members
//(name, gradeToSign, gradeToExecute), the default copy can be tricky. For having
//my own I decide how copying works ans ensure the new object is initializen
//properly. the goal is not about protecting the original (it stays safe anyway).
//The purpose is to control how duplication happens
// 👉 In short:
// The copy constructor is there to safely make duplicates of objects with const members or complex rules.
// It’s not to “not lose” the original, but to make sure the new one is correctly created.

Form& Form::operator=(const Form& other) 
{
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}
//Prints a debug message when a form object is destroyed.
Form::~Form() 
{
    std::cout << "Form " << name << " destroyed" << std::endl;
}

std::string Form::getName() const { return name; }
bool Form::getIsSigned() const { return isSigned; }
int Form::getGradeToSign() const { return gradeToSign; }
int Form::getGradeToExecute() const { return gradeToExecute; }

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() 
{
    return "Form: grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() 
{
    return "Form: grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& f) 
{
    os << "Form \"" << f.getName() << "\", signed: " 
       << (f.getIsSigned() ? "yes" : "no")
       << ", grade to sign: " << f.getGradeToSign()
       << ", grade to execute: " << f.getGradeToExecute();
    return os;
}