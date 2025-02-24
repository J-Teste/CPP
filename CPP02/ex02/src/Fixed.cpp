/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:17:56 by hakgyver          #+#    #+#             */
/*   Updated: 2025/02/13 12:21:00 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

/*-----------------------Membre------------------------------*/

/*Constructors*/
Fixed::Fixed() : value(0)
{
}
Fixed::Fixed(const int Value)
{
	this->value = Value << bits;
}
Fixed::Fixed(const float Value)
{
	this->value = roundf(Value * (1 << bits));
}
Fixed::Fixed(const Fixed &other)
{
    this->value = other.getRawBits();
}

/*Assignement operator*/
Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->value = other.getRawBits();
	return *this;
}

/*Destructor*/
Fixed::~Fixed()
{
}

/*Operators*/

bool Fixed::operator>(const Fixed &other) const 
{
    return this->value > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const 
{
    return this->value < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const 
{
    return this->value >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const 
{
    return this->value <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const 
{
    return this->value == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const 
{
    return this->value != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed &other) const 
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const 
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const 
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
 {
	if (other.value == 0) 
	{
        std::cerr << "Error: Division by zero" << std::endl;
        return Fixed();
	}
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++(void) 
{
    this->value += 1;
    return *this;
}

Fixed &Fixed::operator--(void) 
{
    this->value -= 1;
    return *this;
}

Fixed Fixed::operator++(int) 
{
    Fixed temp = *this;
    this->value += 1;
    return temp;
}

Fixed Fixed::operator--(int) 
{
    Fixed temp = *this;
    this->value -= 1;
    return temp;
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

Fixed &Fixed::min(Fixed &a, Fixed &b) 
{
    return ((a < b) ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) 
{
    return ((a < b) ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) 
{
    return ((a > b) ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) 
{
    return ((a > b) ? a : b);
}

/*-----------------------Non Membre------------------------------*/

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}