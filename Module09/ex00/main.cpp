#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)//counts the num of args pased to the program 
	{
        std::cerr << "Usage: ./btc <input_file>" << std::endl;
        return 1;
    }
    try 
	{
        BitcoinExchange btc;//creating bitcoin object;
        btc.loadDatabase("data.csv"); //subject-provided CSV, reads the data.csv file
        btc.processInput(argv[1]);//reads the file passed as a command line argument
								  //Validated the date, the value, finds the exact rate os that 
								  //date and prints the value
    } 
	//exception
	catch (const std::exception &e) 
	{
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
//GOAL: Simulate a simple Bitcoin exchange calculator
//1. I have a database of Bitcoin prices over time (provided in data.csv)
//2. The input file have dates and ampunt of Bitcoins
//3. If the database is missing, you must use the closest earlie data in the database rate
//4. I must validate inputs: positive numbers, proper dates, not exceeding limits
//5. I have to implement this using at least one STL container (std::map. std::vector)
