/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:18:11 by hakgyver          #+#    #+#             */
/*   Updated: 2025/02/25 12:37:36 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

int main()
{
    ClapTrap bozo("Bozo");
    ClapTrap goofyosaurus("Goofyosaurus");
	std::cout << std::endl;
    bozo.attack("Goofyosaurus");
	std::cout << std::endl;
    goofyosaurus.takeDamage(3);
	std::cout << std::endl;
    goofyosaurus.beRepaired(2);
	std::cout << std::endl;
    for (int i = 0; i < 9; i++)
	{
        bozo.attack("Goofyosaurus");
	}
    bozo.attack("Goofyosaurus");
	std::cout << std::endl;
	bozo.beRepaired(5);
	std::cout << std::endl;
    goofyosaurus.takeDamage(100);
	std::cout << std::endl;
    goofyosaurus.beRepaired(5);
	std::cout << std::endl;
	goofyosaurus.takeDamage(5);
	return (0);
}
