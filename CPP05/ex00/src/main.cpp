/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:58:23 by hakgyver          #+#    #+#             */
/*   Updated: 2025/05/19 16:34:34 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Bureaucrat.hpp"

void sep(std::string s)
{
	std::cout << "\n\n----------- " << s << " -----------\n";
}
int main()
{
	sep("Cas 1 : Impossible de monter en grade");
	try
	{
		Bureaucrat b1("Bozo", 1);
		std::cout << b1;
		b1.incrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	sep("Cas 2 : Impossible de descendre en grade");
	try
	{
		Bureaucrat b2("Bozo", 150);
		std::cout << b2;
		b2.decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	sep("Cas 3 : Impossible de creer un grade > 150");
	try
	{
		Bureaucrat b3("Bozo", 151);
		std::cout << b3;

	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	sep("Cas 4 : Impossible de creer un grade < 0");
	try
	{
		Bureaucrat b4("Bozo", 0);
		std::cout << b4;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	sep("Cas 5 : Tout est ok");
	try
	{
		Bureaucrat b5("Bozo", 50);
		std::cout << b5;
		b5.decrementGrade();
		std::cout << b5;
		b5.incrementGrade();
		std::cout << b5;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}
