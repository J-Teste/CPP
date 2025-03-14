/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:56:33 by hakgyver          #+#    #+#             */
/*   Updated: 2025/03/13 15:50:06 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

WrongCat::WrongCat()
{
	this->_type = "WrongCat";
	std::cout << BRIGHT_GREEN << "From the spark of the animal, a WrongCat is born ! (Default)" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	this->_type = "WrongCat";
	std::cout << BRIGHT_GREEN << "From the spark of the animal, a WrongCat is born ! (Copy)" << RESET << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
	{
		WrongAnimal::operator=(other);
		this->_type = other._type;
		std::cout << BRIGHT_GREEN << "From the spark of the animal, a WrongCat is born ! (=)" << RESET << std::endl;
	}
	return(*this);
}

WrongCat::~WrongCat()
{
	std::cout << BRIGHT_RED << "A WrongCat died, returning to sparks..." << RESET << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << YELLOW <<  "Wrong Meowwwww !!" << RESET << std::endl;
}