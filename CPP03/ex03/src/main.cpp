/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:18:11 by hakgyver          #+#    #+#             */
/*   Updated: 2025/03/07 15:12:37 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

int main()
{
	DiamondTrap bozo("Bozo");
	std::cout << std::endl;
	DiamondTrap goofy("GoofyAusorus");
	std::cout << std::endl;
	bozo.whoAmI();
	std::cout << std::endl;
	goofy.whoAmI();
	std::cout << std::endl;
	bozo.attack("GoofyAusorus");
	goofy.takeDamage(30);
	goofy.attack("Bozo");
	bozo.takeDamage(30);
	bozo.beRepaired(15);
	goofy.beRepaired(20);
	bozo.attack("GoofyAusorus");
	goofy.takeDamage(30);
	std::cout << std::endl;
	return (0);
}


