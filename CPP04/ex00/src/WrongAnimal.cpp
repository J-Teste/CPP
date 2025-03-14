/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:53:36 by hakgyver          #+#    #+#             */
/*   Updated: 2025/03/13 15:49:51 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"


WrongAnimal::WrongAnimal() : _type("Spark")
{
	std::cout << GREEN << "A WrongAnimal of type " << _type << " has been created." << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		this->_type = other._type;
	return(*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED << "A WrongAnimal of type " << _type << " has disapear." << RESET << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << YELLOW << "Random WrongAnimal noise."  << RESET << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->_type);
}
