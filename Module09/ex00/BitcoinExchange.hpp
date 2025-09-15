#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>       //std::map
#include <string>    //std::string
#include <iostream>  //std::cout std::cerr
#include <fstream>   //std::ifstream
#include <sstream>   //std::istringstream
#include <stdexcept> //std::runtime_error

class BitcoinExchange 
{
	private:
    	std::map<std::string, float> _db; // date → exchange rate

	public:
    	BitcoinExchange();
    	BitcoinExchange(const BitcoinExchange &other);//creates copy
    	BitcoinExchange& operator=(const BitcoinExchange &other);
    	~BitcoinExchange();
		
    	void loadDatabase(const std::string &filename);//reads main CSV database and fills _db
    	void processInput(const std::string &filename) const;
		//reads input file, calculates and prints result. Const bc does not modify the object

//Private helper functions
	private:
    	bool validDate(const std::string &date) const;//Check date string is valid
    	bool validValue(const std::string &valueStr, float &value) const;
		//Check value is positive float or int, not too large
    	float getRateForDate(const std::string &date) const;
		//Returns the rate for a date or the closes previous date if the exact match doesen't exist
};

#endif
//_db is a map container where: key-> date as string(YYYY-MM-DD). 
//Keys are automatically stored, this helps finding the closest previos date

