#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <cctype>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	_db;

		static std::string	trim(const std::string &s);
		static bool			isValidDate(const std::string &date);
		static bool			parseValue(const std::string &s, double &out);
		double				getRateForDate(const std::string &date) const;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void	loadDatabase(const std::string &dbFile);
		void	processInput(const std::string &inputFile) const;

};

#endif
