#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _db(other._db)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_db = other._db;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

std::string BitcoinExchange::trim(const std::string &s)
{
	size_t i = 0;
	while (i < s.size() && (s[i] == ' ' || s[i] == '\t'))
		i++;

	size_t j = s.size();
	while (j > i && (s[j - 1] == ' ' || s[j - 1] == '\t'))
		j--;

	return (s.substr(i, j - i));
}

static bool isLeapYear(int y)
{
	if (y % 400 == 0)
		return (true);
	if (y % 100 == 0)
		return (false);
	return ((y % 4) == 0);
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
	if (date.size() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	for (size_t i = 0; i < date.size(); i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return (false);
	}
	int y = std::atoi(date.substr(0, 4).c_str());
	int m = std::atoi(date.substr(5, 2).c_str());
	int d = std::atoi(date.substr(8, 2).c_str());
	if (y < 0 || m < 1 || m > 12 || d < 1)
		return (false);
	int mdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if (m == 2 && isLeapYear(y))
		mdays[1] = 29;
	if (d > mdays[m - 1])
		return (false);
	return (true);
}

bool BitcoinExchange::parseValue(const std::string &s, double &out)
{
	std::string t = trim(s);
	if (t.empty())
		return (false);
	if (t[0] == '+')
		return (false);
	char *end = 0;
	out = std::strtod(t.c_str(), &end);
	if (end == t.c_str())
		return (false);
	while (*end)
	{
		if (*end != ' ' && *end != '\t')
			return (false);
		++end;
	}
	return (true);
}

void BitcoinExchange::loadDatabase(const std::string &dbFile)
{
	std::ifstream file(dbFile.c_str());
	if (!file)
		throw std::runtime_error("Error: could not open data.csv.");
	std::string line;
	if (std::getline(file, line))
	{
		if (trim(line) != "date,exchange_rate")
		{
			std::istringstream ss(line);
			std::string date;
			std::string rateStr;
			double rate;
			if (std::getline(ss, date, ',') && std::getline(ss, rateStr))
			{
				date = trim(date);
				if (isValidDate(date) && parseValue(rateStr, rate))
					_db[date] = rate;
			}
		}
	}
	while (std::getline(file, line))
	{
		std::istringstream ss(line);
		std::string date;
		std::string rateStr;
		double rate;
		if (!std::getline(ss, date, ',') || !std::getline(ss, rateStr))
			continue;
		date = trim(date);
		if (!isValidDate(date))
			continue;
		if (!parseValue(rateStr, rate))
			continue;
		_db[date] = rate;
	}
	if (_db.empty())
		throw std::runtime_error("Error: database is empty or invalid.");
}

double BitcoinExchange::getRateForDate(const std::string &date) const
{
	std::map<std::string, double>::const_iterator it = _db.lower_bound(date);

	if (it != _db.end() && it->first == date)
		return (it->second);

	if (it == _db.begin())
		throw std::runtime_error("Error: bad input => " + date);

	--it;
	return (it->second);
}

void BitcoinExchange::processInput(const std::string &inputFile) const
{
	std::ifstream file(inputFile.c_str());
	if (!file)
		throw std::runtime_error("Error: could not open file.");

	std::string line;
	if (std::getline(file, line))
	{
		if (trim(line) != "date | value")
		{
			std::istringstream ss(line);
			std::string datePart;
			std::string valuePart;

			if (std::getline(ss, datePart, '|') && std::getline(ss, valuePart))
			{
				std::string date = trim(datePart);
				double value;

				if (!isValidDate(date))
					std::cerr << "Error: bad input => " << trim(line) << std::endl;
				else if (!parseValue(valuePart, value))
					std::cerr << "Error: bad input => " << trim(line) << std::endl;
				else if (value < 0)
					std::cerr << "Error: not a positive number." << std::endl;
				else if (value > 1000)
					std::cerr << "Error: too large a number." << std::endl;
				else
				{
					double rate = getRateForDate(date);
					std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
				}
			}
			else
				std::cerr << "Error: bad input => " << trim(line) << std::endl;
		}
	}

	while (std::getline(file, line))
	{
		if (trim(line).empty())
			continue;

		std::istringstream ss(line);
		std::string datePart;
		std::string valuePart;

		if (!std::getline(ss, datePart, '|') || !std::getline(ss, valuePart))
		{
			std::cerr << "Error: bad input => " << trim(line) << std::endl;
			continue;
		}

		std::string date = trim(datePart);
		double value;

		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << trim(line) << std::endl;
			continue;
		}
		if (!parseValue(valuePart, value))
		{
			std::cerr << "Error: bad input => " << trim(line) << std::endl;
			continue;
		}
		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}
		try
		{
			double rate = getRateForDate(date);
			std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}