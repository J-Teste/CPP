/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:53:55 by hakgyver          #+#    #+#             */
/*   Updated: 2025/03/06 15:41:58 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(), _isGuarding(false)
{
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
	std::cout << BRIGHT_GREEN << "ScavTrap " << _name << " is born!" << RESET << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name), _isGuarding(false)
{
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
	this->_isGuarding = false;
	std::cout << BRIGHT_GREEN << "ScavTrap " << _name << " is born!" << RESET << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << BRIGHT_RED << "ScavTrap " << _name << " has been scrapped..." << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	_isGuarding = other._isGuarding;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		_isGuarding = other._isGuarding;
	}
	return (*this);
}

void ScavTrap::attack(const std::string &target)
{
	if (_ep > 0 && _hp > 0)
	{
		std::cout << "ScavTrap " << _name << BRIGHT_RED << " rolls on " << RESET << target << ", causing " << BRIGHT_RED <<  _ad << RESET << " Points of damage." << std::endl;
		_ep--;
	}
	else
		std::cout << BRIGHT_YELLOW << "ScavTrap " << _name << " cannot attack." << RESET << std::endl;
}

void ScavTrap::guardGate()
{
	if (!_isGuarding)
	{
		std::cout << BRIGHT_CYAN << "ScavTrap " << _name << " is now in Gate Keeper mode." << RESET << std::endl;
		_isGuarding = true;
	}
	else
		std::cout << BRIGHT_YELLOW << "ScavTrap " << _name << " is already in Gate Keeper mode." << RESET << std::endl;
}
