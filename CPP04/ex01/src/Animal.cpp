/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:30:58 by hakgyver          #+#    #+#             */
/*   Updated: 2025/03/20 16:44:46 by jteste           ###   ########.fr       */
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
	std::cout << GREEN << "An Animal has been created. (Copy)" << RESET << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << GREEN << "An Animal has been created. (operator=)" << RESET << std::endl;
	return(*this);
}

Animal::~Animal()
{
	std::cout << RED << "An Animal of type " << _type << " has disapear. (Default)" << RESET << std::endl;
}

void Animal::makeSound() const
{
	std::cout << YELLOW << "Random animal noise." << RESET << std::endl;
}

std::string Animal::getType() const
{
	return(this->_type);
}
