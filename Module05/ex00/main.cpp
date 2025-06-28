#include "Bureaucrat.hpp"
int main() {
    Bureaucrat bob("Bob", 200); // Grade 200 is invalid
    std::cout << bob << std::endl;
    return 0;
}

// int main() 
// {
//     try 
//     {
//         Bureaucrat Andrei("Andrei", 151);
//         std::cout << Andrei << std::endl;
//         Andrei.incrementGrade(); // should throw
//     } 
//     catch (std::exception& e) 
//     {
//         std::cout << "Exception caught: " << e.what() << std::endl;
//     }

//     try 
//     {
//         Bureaucrat Meritxell("Meritxell", 149); // should throw
//     } 
//     catch (std::exception& e) 
//     {
//         std::cout << "Exception caught: " << e.what() << std::endl;
//     }

//     return 0;
// }
//The try block runs first.
// If something throws an exception (e.g., throw 
// Bureaucrat::GradeTooLowException();), execution 
// jumps to the catch block.
// The program prints the error message and keeps running safely.