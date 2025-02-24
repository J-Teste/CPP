/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:17:56 by hakgyver          #+#    #+#             */
/*   Updated: 2025/02/13 10:51:55 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

/*-----------------------Membre------------------------------*/

/*Constructors*/
Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int Value)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = Value << bits;
}
Fixed::Fixed(const float Value)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(Value * (1 << bits));
}
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
    this->value = other.getRawBits();
}

/*Assignement operator*/
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &other)
		this->value = other.getRawBits();
	return *this;
}

/*Destructor*/
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/*Member functions*/
int Fixed::getRawBits(void) const
{
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->value) / (1 << bits));
}

int Fixed::toInt(void) const
{
	return (this->value >> bits);
}


/*-----------------------Non Membre------------------------------*/

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}