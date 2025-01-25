#include <iostream>
#include <fstream> // For file streams

int main(int argc, char *argv[]) 
{
    if(argc != 4)
    {
        std::cout << "ERROR: three arguments are needed" << std::endl;
        return 1;
    }
    std::ifstream inputFile(argv[1], std::ios::in);  // Open the source file for reading
    std::ofstream outputFile(std::string(argv[1])+".replace", std::ios::out);  // Open the destination file for writing

    if (!inputFile) 
    {
        std::cerr << "Error: Could not open source file." << std::endl;
        return 1;  // Exit with error code
    }

    if (!outputFile)
    {
        std::cerr << "Error: Could not open destination file." << std::endl;
        return 1;  // Exit with error code
    }

    std::string s1 = argv[2];
    std::string s2 = argv[3]; //lo declaro para que no problemas que el doble puntero por ahi.

    // Read from source and write to destination
    std::string line;
    while (std::getline(inputFile, line))  // Read one line at a time
    {
        size_t index;
        int i = 0;
        if((index = line.find(s1)) != std::string::npos)
        {
            while(line[index] != '\0')
            {
                line[index] = s2[i]; // hay que controlar si s2 se ha copiado completamente porque si s2 es mas larga que s1 se lia
                index++;
                i++;
            }
        }
        outputFile << line << "\n";         // Write each line to the destination file
    }  

    // Close the files
    inputFile.close();
    outputFile.close();

    std::cout << "File copied successfully!" << std::endl;
    return 0;
}
//Vigilar que pasa si hay dos s1 en la misma linea, es decir la misma palabra a sustituir dos veces
//Y un error asqueroso de que no se puede abrir el file en vscode
