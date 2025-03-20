/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:26:26 by hakgyver          #+#    #+#             */
/*   Updated: 2025/03/20 18:03:35 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog()
{
	this->_type = "Dog";
	this->brain = new Brain();
	std::cout << BRIGHT_GREEN << "From the spark of the animal, a Dog is born ! (Default)" << RESET << std::endl;
}

Dog::Dog(const Dog &other) : AAnimal(other)
{
	this->_type = "Cat";
	std::cout << BRIGHT_GREEN << "From the spark of the animal, a Dog is born ! (Copy)" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		this->_type = other._type;
		AAnimal::operator=(other);
		std::cout << BRIGHT_GREEN << "From the spark of the animal, a Dog is born ! (=)" << RESET << std::endl;
	}
	return(*this);
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << BRIGHT_RED << "A Dog died, returning to sparks..." << RESET << std::endl;
}

void Dog::makeSound() const
{
	std::cout << YELLOW <<  "Wooof !!" << RESET << std::endl;
}

Brain* Dog::getBrain() const
{
	return this->brain;
}

std::string Dog::getType() const
{
	return(this->_type);
}