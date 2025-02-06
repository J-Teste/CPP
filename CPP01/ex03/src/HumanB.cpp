/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:08:53 by hakgyver          #+#    #+#             */
/*   Updated: 2025/01/30 13:23:12 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(nullptr)
{
}

HumanB::~HumanB()
{
}
void HumanB::attack() const
{
	if(_weapon)
		std::cout << this->_name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << this->_name << " has no weapon to attack with" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}
