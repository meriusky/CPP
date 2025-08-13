#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& n, int signGrade, int execGrade)
    : name(n), isSigned(false), gradeToSign(signGrade), gradeToExecute(execGrade) 
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
    std::cout << "Form " << name << " created" << std::endl;
}

Form::Form(const Form& other)
    : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

Form& Form::operator=(const Form& other) {
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}

Form::~Form() {
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

const char* Form::GradeTooHighException::what() const throw() {
    return "Form: grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form: grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "Form \"" << f.getName() << "\", signed: " 
       << (f.getIsSigned() ? "yes" : "no")
       << ", grade to sign: " << f.getGradeToSign()
       << ", grade to execute: " << f.getGradeToExecute();
    return os;
}

