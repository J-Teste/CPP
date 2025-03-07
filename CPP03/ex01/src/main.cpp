/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:18:11 by hakgyver          #+#    #+#             */
/*   Updated: 2025/03/06 15:41:28 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

int main()
{
	ClapTrap bozo("Bozo");
	ScavTrap scav("Goofyosaurus");
	
	std::cout << std::endl;
	bozo.attack("Goofyosaurus");
	std::cout << std::endl;
	scav.attack("Bozo");
	std::cout << std::endl;
	scav.guardGate();
	std::cout << std::endl;
	scav.guardGate();
	std::cout << std::endl;
	bozo.takeDamage(3);
	scav.takeDamage(10);
	std::cout << std::endl;
	scav.beRepaired(5);
	std::cout << std::endl;
	scav.attack("Bozo");
	bozo.attack("Goofyosaurus");
	std::cout << std::endl;
	scav.takeDamage(150);
	bozo.takeDamage(100);
	return (0);
}

