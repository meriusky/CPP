#include <iostream>
#include <fstream> // For file streams
#include <cstring> //For strlen

int main(int argc, char *argv[]) 
{
    if(argc != 4)
    {
        std::cout << "ERROR: three arguments are needed" << std::endl;
        return 1;
    }
    std::ifstream inputFile(argv[1], std::ios::in);  // Open the source file for reading
    std::ofstream outputFile((std::string(argv[1])+".replace").c_str(), std::ios::out);  // Open the destination file for writing

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
    std::string s2 = argv[3]; //I declare it for not having problems with the double pointer

    int lineNumber = 0; // To put the \n after the line and not at the end of the file
    std::string line;
    std::string newLine;
    while (std::getline(inputFile, line))  // Read one line at a time
    {
        if (lineNumber != 0)
            outputFile << "\n";
        lineNumber++;
        newLine = line;
        size_t index = 0;
        while((index = newLine.find(s1, index)) != std::string::npos)
        {
            std::string startLine = newLine.substr(0, index);
            std::string endLine = newLine.substr(index + std::strlen(s1.c_str()), std::strlen(newLine.c_str()) - index + std::strlen(s1.c_str()));
            newLine = startLine + s2 + endLine;
            index += std::strlen(s2.c_str());
        }
        outputFile << newLine;         // Write each line to the destination file
    }  

    // Close the files
    inputFile.close();
    outputFile.close();

    std::cout << "File copied successfully!" << std::endl;
    return 0;
}
