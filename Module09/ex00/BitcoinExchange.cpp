#include "BitcoinExchange.hpp"
#include <cstdlib>  // for atoi, atof


// Constructors
BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _db(other._db) {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other) 
{
    if (this != &other) _db = other._db;
    return *this;
}
BitcoinExchange::~BitcoinExchange() {}

// Load the CSV database
void BitcoinExchange::loadDatabase(const std::string &filename) 
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database file.");

    std::string line;
    std::getline(file, line); // skip header
    while (std::getline(file, line)) 
	{
        std::istringstream ss(line);
        std::string date, rateStr;
        if (std::getline(ss, date, ',') && std::getline(ss, rateStr)) 
		{
			float rate = atof(rateStr.c_str());
            _db[date] = rate;
        }
    }
    file.close();
}

// Process input.txt
void BitcoinExchange::processInput(const std::string &filename) const 
{
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // skip header

    while (std::getline(file, line)) 
	{
        std::istringstream ss(line);
        std::string date, valueStr;

        if (!(std::getline(ss, date, '|') && std::getline(ss, valueStr))) 
		{
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        // trim spaces
        date.erase(date.find_last_not_of(" \t") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" \t"));

        if (!validDate(date)) 
		{
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        float value;
        if (!validValue(valueStr, value))
            continue;
        try 
		{
            float rate = getRateForDate(date);
            std::cout << date << " => " << value << " = " << value * rate << std::endl;
        } 
		catch (const std::exception &e) 
		{
            std::cerr << e.what() << std::endl;
        }
    }
}

// Validate date (YYYY-MM-DD basic check)
bool BitcoinExchange::validDate(const std::string &date) const 
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') return false;
	int y = atoi(date.substr(0, 4).c_str());
    int m = atoi(date.substr(5, 2).c_str());
    int d = atoi(date.substr(8, 2).c_str());
    if (y < 2000 || m < 1 || m > 12 || d < 1 || d > 31) return false;
    return true;
}

// Validate value
bool BitcoinExchange::validValue(const std::string &valueStr, float &value) const 
{
    value = atof(valueStr.c_str());
    if (value < 0) 
	{
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value > 1000) 
	{
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

// Get rate for date (closest earlier date)
float BitcoinExchange::getRateForDate(const std::string &date) const 
{
    std::map<std::string, float>::const_iterator it = _db.lower_bound(date);
    if (it == _db.end() || it->first != date) 
	{
        if (it == _db.begin())
            throw std::runtime_error("Error: date not found and no earlier date.");
        --it;
    }
    return it->second;
}

