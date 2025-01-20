#include <iostream>  // For std::cout, std::cin
#include <cctype>    // For std::toupper

void toUpperCase(char* str)
{
	int i = 0;
    for (str[i] != '\0'; ++i) 
	{
        str[i] = std::toupper(str[i]);
    }
}

int main(int argc, char* argv[]) 
{
    if (argc != 2) 
	{ // Ensure exactly one argument is provided
        std::cout << "Usage: " << argv[0] << " <string>\n";
        return 1;
    }
    toUpperCase(argv[1]);
    std::cout << "Uppercase string: " << argv[1] << std::endl;
    return 0;
}

