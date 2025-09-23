#include "BitcoinExchange.hpp"
#include <cstdlib>  // for atoi, atof


// Constructors
BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _db(other._db) {}//copy _db
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)//deep copy _db 
{
    if (this != &other) _db = other._db;
    return *this;
}
BitcoinExchange::~BitcoinExchange() {}

//Load the CSV database:reads CSV database and fills _db
void BitcoinExchange::loadDatabase(const std::string &filename) 
{
    std::ifstream file(filename.c_str());//opens CSV
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database file.");

    std::string line;
    std::getline(file, line);//skips CSV header
    while (std::getline(file, line))//reads line one by one
	{
        std::istringstream ss(line);
        std::string date, rateStr;
		//for each data line, splits on the comma
        if (std::getline(ss, date, ',') && std::getline(ss, rateStr)) 
		{
			float rate = atof(rateStr.c_str());//converts the string to float
            _db[date] = rate;
        }
    }
    file.close();
}

// Process input.txt: read the user input file and print conversions or errors
void BitcoinExchange::processInput(const std::string &filename) const 
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())//is opening fails 
	{
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // skip header

    while (std::getline(file, line))//splits line using | as delimiter 
	{
        std::istringstream ss(line);
        std::string date, valueStr;

        if (!(std::getline(ss, date, '|') && std::getline(ss, valueStr))) 
		{
            std::cerr << "Error: bad input => " << line << std::endl;//if fails
            continue;
        }

        //removes trailing whitespace at the end of date
        date.erase(date.find_last_not_of(" \t") + 1);
		//removes leadign whitespace at the start of valuestr
        valueStr.erase(0, valueStr.find_first_not_of(" \t"));

        if (!validDate(date))//checl the date 
		{
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        float value;//converts str to float and checks positivity and upper bound
        if (!validValue(valueStr, value))
            continue;
        try//returns the rate for date, or throws in there's no earlier date to use
		{
            float rate = getRateForDate(date);
            std::cout << date << " => " << value << " = " << value * rate << std::endl;//successful
        } 																			   // prints
		catch (const std::exception &e) 
		{
            std::cerr << e.what() << std::endl;
        }
    }
}
// Validate date (YYYY-MM-DD with proper month/day limits)
bool BitcoinExchange::validDate(const std::string &date) const 
{
    // Check length and dash positions
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') 
        return false;

    // Extract year, month, day
    int y = atoi(date.substr(0, 4).c_str());
    int m = atoi(date.substr(5, 2).c_str());
    int d = atoi(date.substr(8, 2).c_str());

    // Year must be reasonable (example: Bitcoin started 2009)
    if (y < 2000 || m < 1 || m > 12 || d < 1) 
        return false;

    // Days in each month (default February has 28 days)
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 
                           31, 31, 30, 31, 30, 31};

    // Handle leap year for February
    bool leap = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
    if (leap) 
        daysInMonth[1] = 29;

    // Check if day is within the correct month’s range
    if (d > daysInMonth[m - 1]) 
        return false;

    return true;
}

//Validate value: Check value is positive float or int, not too large
bool BitcoinExchange::validValue(const std::string &valueStr, float &value) const 
{
    value = atof(valueStr.c_str());//to covert string to float
    if (value < 0)//Rejects negative numbers 
	{
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value > 1000)//Rejects values greater that 1000 
	{
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

//Get rate for date: Gets the closest earlier date in case they don't match
float BitcoinExchange::getRateForDate(const std::string &date) const 
{
	//lower_bound(date) finds the first element not less that date
    std::map<std::string, float>::const_iterator it = _db.lower_bound(date);
    if (it == _db.end() || it->first != date) 
	{
        if (it == _db.begin())
            throw std::runtime_error("Error: date not found and no earlier date.");
        --it;
    }
    return it->second;
}

