/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:46:22 by hakgyver          #+#    #+#             */
/*   Updated: 2025/03/07 14:44:23 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
	std::cout << GREEN << "FragTrap " << _name << " is here, fully armed with explosive personality!" << RESET << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
	std::cout << GREEN << "FragTrap " << _name << " is here, fully armed with explosive personality!" << RESET << std::endl;
}

FragTrap::FragTrap(int hp, int ad) : ClapTrap("Bozo")
{
	this->_hp = hp;
	this->_ad = ad;
	std::cout << GREEN << "FragTrap " << _name << " is here, fully armed with explosive personality!" << RESET << std::endl;
}


FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);	
}

FragTrap::~FragTrap()
{
	std::cout << RED<< "FragTrap " << _name << " has exploded... quite literally." << RESET << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << CYAN << "FragTrap " << _name << " is raising its hand... come on, give me a high-five!" << RESET << std::endl;
}
