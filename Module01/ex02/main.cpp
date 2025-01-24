#include <iostream>
int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;// Ptr: Guarda l'adreça de la variable en questio
    std::string& stringREF = str; //Referencia: es com posar una altre nom a la variable, NO pot ser NULL i la pots modificar

    std::cout << "Memory address str: " << &str << std::endl;
    std::cout << "Memory address stringPTR : " << stringPTR << std::endl;
    std::cout << "Memory address stringREF : " << &stringREF << std::endl;

    std::cout << "Value of str: " << str << std::endl;
    std::cout << "Value of stringPTR : " << *stringPTR << std::endl;
    std::cout << "Value of stringREF : " << stringREF << std::endl;
    return(0);
}
