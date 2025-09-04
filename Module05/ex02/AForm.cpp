#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Constructor with checks
AForm::AForm(const std::string& n, int signGrade, int execGrade)
    : name(n), isSigned(false), gradeToSign(signGrade), gradeToExecute(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
    std::cout << "AForm " << name << " created" << std::endl;
}

// Copy constructor: needed to safely make duplicates of objects. It's not for "not losing" the original but to make sure the new one is correctly created
AForm::AForm(const AForm& other)
    : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

AForm& AForm::operator=(const AForm& other) 
{
    if (this != &other) 
	{
        this->isSigned = other.isSigned;
    }
    return *this;
}

AForm::~AForm() 
{
    std::cout << "AForm " << name << " destroyed" << std::endl;
}

// Getters
std::string AForm::getName() const { return name; }
bool AForm::getIsSigned() const { return isSigned; }
int AForm::getGradeToSign() const { return gradeToSign; }
int AForm::getGradeToExecute() const { return gradeToExecute; }

// beSigned method
void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

// Exception messages
const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm: grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm: grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "AForm: form is not signed!";
}

// Operator overload
// //📍Remember os: os is the stream we’re printing to. It could be std::cout, std::cerr, or even a file stream. We use it instead of hardcoding std::cout so the operator is more flexible.
std::ostream& operator<<(std::ostream& os, const AForm& f) 
{
    os << "Form \"" << f.getName() << "\", signed: "
       << (f.getIsSigned() ? "yes" : "no")
       << ", grade to sign: " << f.getGradeToSign()
       << ", grade to execute: " << f.getGradeToExecute();
    return os;
}
