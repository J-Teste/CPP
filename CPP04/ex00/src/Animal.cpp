/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:30:58 by hakgyver          #+#    #+#             */
/*   Updated: 2025/03/13 15:49:11 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

Animal::Animal() : _type("Spark")
{
	std::cout << GREEN << "An Animal has been created. (Default)" << RESET << std::endl;
}

Animal::Animal(const Animal &other)
{
	*this = other;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
		this->_type = other._type;
	return(*this);
}

Animal::~Animal()
{
	std::cout << RED << "An Animal of type " << _type << " has disapear." << RESET << std::endl;
}

void Animal::makeSound() const
{
	std::cout << YELLOW << "Random animal noise." << RESET << std::endl;
}

std::string Animal::getType() const
{
	return(this->_type);
}
