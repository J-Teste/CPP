/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:44:37 by hakgyver          #+#    #+#             */
/*   Updated: 2025/03/13 15:49:24 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	std::cout << BRIGHT_GREEN << "From the spark of the animal, a Cat is born ! (Default)" << RESET << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	this->_type = "Cat";
	std::cout << BRIGHT_GREEN << "From the spark of the animal, a Cat is born ! (Copy)" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		this->_type = other._type;
		std::cout << BRIGHT_GREEN << "From the spark of the animal, a Cat is born ! (=)" << RESET << std::endl;
	}
	return(*this);
}

Cat::~Cat()
{
	std::cout << BRIGHT_RED << "A Cat died, returning to sparks..." << RESET << std::endl;
}

void Cat::makeSound() const
{
	std::cout << YELLOW << "Meowwwww !!" << RESET << std::endl;
}