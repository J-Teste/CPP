/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:30:58 by hakgyver          #+#    #+#             */
/*   Updated: 2025/03/20 23:06:33 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AAnimal.hpp"


AAnimal::AAnimal() : _type("Spark")
{
	std::cout << GREEN << "An Animal has been created. (Default)" << RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	*this = other;
	std::cout << GREEN << "An Animal has been created. (Copy)" << RESET << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << GREEN << "An Animal has been created. (operator=)" << RESET << std::endl;
	return(*this);
}

AAnimal::~AAnimal()
{
	std::cout << RED << "An Animal of type " << _type << " has disapear. (Base class)" << RESET << std::endl;
}


std::string AAnimal::getType() const
{
	return(this->_type);
}

