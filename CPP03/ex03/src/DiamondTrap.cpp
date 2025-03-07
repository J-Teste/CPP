/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:51:38 by hakgyver          #+#    #+#             */
/*   Updated: 2025/03/07 15:11:50 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Bozo_clap_name"), FragTrap(100, 30), ScavTrap(50)
{
    this->_name = "Bozo";
	std::cout << GREEN << "DiamondTrap " << _name << " has been forged, a mix of ScavTrap’s resilience and FragTrap’s firepower!" << RESET << std::endl;

}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), FragTrap(100, 30), ScavTrap(50)
{
    this->_name = name;
	std::cout << GREEN << "DiamondTrap " << _name << " has been forged, a mix of ScavTrap’s resilience and FragTrap’s firepower!" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), FragTrap(other), ScavTrap(other)
{
    *this = other;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        _name = other._name;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << RED << "DiamondTrap " << _name << " crumbles into dust... But legends never die!" << RESET << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "Who am I? I am " << _name << ", the ultimate hybrid! My ClapTrap name is " << ClapTrap::_name << "." << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

