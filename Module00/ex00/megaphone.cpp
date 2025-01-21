#include <iostream>  //Llibreria per  std::cout, std::cin
#include <cctype>    //Llibreria per std::toupper

void UpperCase(char* str)
{
	int i = 0;
    while (str[i] != '\0') 
	{
        str[i] = std::toupper(str[i]); //funcio que transforma en majuscula
		i++;
    }
}

int main(int argc, char* argv[]) 
{
	int i = 1;
    if (argc < 2) 
	{
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return 1;
    }
	while(argv[i] != NULL)
	{
		UpperCase(argv[i]);
		std::cout  << argv[i];
		i++;
	}
	std::cout << std::endl;
	return 0;
}
