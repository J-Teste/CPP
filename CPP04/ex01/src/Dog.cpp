/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:26:26 by hakgyver          #+#    #+#             */
/*   Updated: 2025/03/13 17:01:20 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog()
{
	this->_type = "Dog";
	this->brain = new Brain();
	std::cout << BRIGHT_GREEN << "From the spark of the animal, a Dog is born ! (Default)" << RESET << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	this->_type = "Cat";
	std::cout << BRIGHT_GREEN << "From the spark of the animal, a Dog is born ! (Copy)" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		this->_type = other._type;
		Animal::operator=(other);
		std::cout << BRIGHT_GREEN << "From the spark of the animal, a Dog is born ! (=)" << RESET << std::endl;
	}
	return(*this);
}

Dog::~Dog()
{
	delete[] this->brain;
	std::cout << BRIGHT_RED << "A Dog died, returning to sparks..." << RESET << std::endl;
}

void Dog::makeSound() const
{
	std::cout << YELLOW <<  "Wooof !!" << RESET << std::endl;
}