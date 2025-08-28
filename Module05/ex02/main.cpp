#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat alice("Alice", 1);    // Top rank bureaucrat
        Bureaucrat bob("Bob", 140);      // Lower rank bureaucrat
        Bureaucrat charlie("Charlie", 50);

        std::cout << "=== Creating Forms ===" << std::endl;
        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Marvin");
        PresidentialPardonForm pardon("Ford Prefect");

        std::cout << std::endl << "=== Trying to sign forms ===" << std::endl;
        bob.signForm(shrub);     // Should succeed (sign grade 145)
        bob.signForm(robot);     // Should fail (needs 72)
        alice.signForm(robot);   // Should succeed
        charlie.signForm(pardon);// Should fail (needs 25)
        alice.signForm(pardon);  // Should succeed

        std::cout << std::endl << "=== Trying to execute forms ===" << std::endl;
        bob.executeForm(shrub);     // Should succeed (exec grade 137, Bob is 140 → too low!)
        charlie.executeForm(robot); // Should succeed/fail randomly
        alice.executeForm(pardon);  // Should succeed

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
