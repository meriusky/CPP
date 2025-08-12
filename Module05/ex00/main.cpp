#include "Bureaucrat.hpp"
// int main() {
//     Bureaucrat bob("Bob", 200); // Grade 200 is invalid
//     std::cout << bob << std::endl;
//     return 0;
// }

// int main() 
// {
//     try 
//     {
//         Bureaucrat Andrei("Andrei", 200);
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
// // The try block runs first.
// // If something throws an exception (e.g., throw 
// // Bureaucrat::GradeTooLowException();), execution 
// // jumps to the catch block.
// // The program prints the error message and keeps running safely.
#include <iostream>
#include "Bureaucrat.hpp"

int main() {
    std::cout << "=== Creating valid bureaucrats ===" << std::endl;
    Bureaucrat bob("Bob", 40);
    Bureaucrat alice("Alice", 2);

    std::cout << bob << std::endl;
    std::cout << alice << std::endl;

    std::cout << "\n=== Testing grade increment/decrement ===" << std::endl;
    std::cout << "before" << bob << std::endl;
    bob.incrementGrade();
    alice.incrementGrade();
    std::cout << "\n increment Grade" << std::endl;
    std::cout << bob << std::endl;
    std::cout << alice << std::endl;
    bob.decrementGrade();
    alice.decrementGrade();
    std::cout << "\n decrement Grade" << std::endl;
    std::cout << bob << std::endl;
    std::cout << alice << std::endl;

    std::cout << "\n=== Creating invalid bureaucrats ===" << std::endl;
    try 
    {
        Bureaucrat tooHigh("High", 0); // Invalid
    } 
    catch (const std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
    }
    try 
    {
        Bureaucrat tooLow("Low", 151); // Invalid
    } 
    //For weird errors
    catch (const std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}