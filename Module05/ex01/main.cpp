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

int main() 
{
    try
    {
        std::cout << "=== Creating bureaucrats ===" << std::endl;
        Bureaucrat bob("Bob", 2);
        Bureaucrat alice("Alice", 140);

    
        std::cout << bob << std::endl;
        std::cout << alice << std::endl;

        std::cout << "=== TESTING GRADE ⬆️increment/decrement⬇️ ===" << std::endl;
    // std::cout << "before" << bob << std::endl;
        bob.incrementGrade();
        alice.incrementGrade();
        std::cout << "\n ⬆️increment Grade⬆️" << std::endl;
        std::cout << bob << std::endl;
        std::cout << alice << std::endl;
        bob.decrementGrade();
        alice.decrementGrade();
        std::cout << "\n ⬇️decrement Grade⬇️" << std::endl;
        std::cout << bob << std::endl;
        std::cout << alice << std::endl;
    }
    // std::cout << "\n=== Creating invalid bureaucrats ===" << std::endl;
    // try 
    // {
    //     Bureaucrat tooHigh("High", 0); // Invalid
    // } 
    catch (const std::exception& e) 
    {                                //📌What is std::cerr?
        std::cerr << e.what() << std::endl; //Is the "cousin" of std::cout but for errors and ist
    }                                       //unbuffered(prints immediately), thats why is good for                                      
    // try                                  //errors. It prints faster than the crush 
    // {                                     
    //     Bureaucrat tooLow("Low", 151); // Invalid
    // } 
    // //For weird errors
    // catch (const std::exception& e) 
    // {
    //     std::cerr << e.what() << std::endl;
   // }

    return 0;
}