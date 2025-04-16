/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:03:37 by hakgyver          #+#    #+#             */
/*   Updated: 2025/04/16 03:25:45 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"


ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
	(void)other;
	return(*this);
}

ScalarConverter::~ScalarConverter()
{
}

/*-------------------------------------------------------------------------------*/

bool isChar(std::string const &s) 
{
	return (s.length() == 1 && !std::isdigit(s[0]));
}

bool isInt(std::string const &s) 
{
	char *end;
	std::strtol(s.c_str(), &end, 10);
	return (*end == '\0');
}

bool isFloat(std::string const &s) 
{
	if (s == "-inff" || s == "+inff" || s == "nanf")
		return (true);
	char *end;
	std::strtof(s.c_str(), &end); 
	return (*end == 'f');
}

bool isDouble(std::string const &s) 
{
	if (s == "-inf" || s == "+inf" || s == "nan")
		return (true);
	char *end;
	std::strtod(s.c_str(), &end);
	return (*end == '\0');
}

Literal detectType(std::string const &s) 
{
	if (isChar(s))
		return (CHAR);
	if (isInt(s))
		return (INT);
	if (isFloat(s))
		return (FLOAT);
	if (isDouble(s))
		return (DOUBLE);
	return (INVALID);
}

void printConversions(char c) 
{
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void printConversions(int n) 
{
	if (n >= 32 && n <= 126)
		std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
	else if (n >= 0 && n < 256)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << n << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(n) << std::endl;
}

void printConversions(float f) 
{
	if (std::isnan(f) || std::isinf(f) || f < 0 || f > 255)
		std::cout << "char: impossible" << std::endl;
	else if (f >= 32 && f <= 126)
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	if (f >= static_cast<float>(std::numeric_limits<int>::min()) && f <= static_cast<float>(std::numeric_limits<int>::max()))
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void printConversions(double d)
{
	if (std::isnan(d) || std::isinf(d) || d < 0 || d > 255)
		std::cout << "char: impossible" << std::endl;
	else if (d >= 32 && d <= 126)
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	if (d >= static_cast<double>(std::numeric_limits<int>::min()) && d <= static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}


void ScalarConverter::convert(std::string const &literal) 
{
	Literal type = detectType(literal);
	switch (type) 
	{
		case CHAR:
			printConversions(literal[0]);
			break;
		case INT:
			printConversions(std::atoi(literal.c_str()));
			break;
		case FLOAT:
			printConversions(std::strtof(literal.c_str(), NULL));
			break;
		case DOUBLE:
			printConversions(std::strtod(literal.c_str(), NULL));
			break;
		default:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
	}
}
