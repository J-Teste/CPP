/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:18:09 by hakgyver          #+#    #+#             */
/*   Updated: 2025/03/07 15:12:18 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Bozo"), _hp(10), _ep(10), _ad(0)
{
	std::cout << GREEN << "Hello, I'm a ClapTrap called " << _name << ". I have " << _hp << " Hit points, " << _ep << " Energie points and " << _ad << " Attack damage. Nice to meet you." << RESET << std::endl;
}
ClapTrap::ClapTrap(const std::string name) : _name(name), _hp(10), _ep(10), _ad(0)
{
	std::cout <<  GREEN << "Hello, I'm a ClapTrap called " << _name << ". I have " << _hp << " Hit points, " << _ep << " Energie points and " << _ad << " Attack damage. Nice to meet you." << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_ad = other._ad;
		this->_ep = other._ep;
		this->_hp = other._hp;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << RED << "Hey it's me, the ClapTrap " << _name << " I'm leaving now...\n" << RESET << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (_ep > 0 && _hp > 0)
	{
		std::cout << "ClapTrap " << _name << RED << " attacks " << RESET << target << ", causing " << RED <<  _ad << RESET << " Points of damage." << std::endl;
		_ep--;
	}
	else
		std::cout << YELLOW << "ClapTrap " << _name << " cannot attack." << RESET << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hp <= 0)
		std::cout << YELLOW << "Claptrap " << _name << " is dead already..." << RESET << std::endl;
	else if (_hp <= (int)amount)
	{
		std::cout << "Claptrap " << _name << " took " << RED << amount << RESET << " damages and " << RED << "died..." << RESET << std::endl;
		_hp = 0;
	}
	else
	{
		std::cout << "Claptrap " << _name << " took " << RED <<  amount << RESET << " damages." << std::endl;
		_hp -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_ep > 0 && _hp > 0)
	{
		std::cout << "ClapTrap " << _name << GREEN << " repairs" << RESET << " himself and gained " << GREEN << amount << RESET << " Hit points." << std::endl;
		_hp += amount;
		_ep--;
	}
	else
		std::cout << YELLOW << "ClapTrap " << _name << " cannot repair." << RESET << std::endl;
}
