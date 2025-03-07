/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:18:11 by hakgyver          #+#    #+#             */
/*   Updated: 2025/03/06 16:29:46 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"

int main()
{
	FragTrap frag1("Boomer");
	FragTrap frag2("Grenade");
	std::cout << std::endl;
	frag1.attack("Grenade");
	std::cout << std::endl;
	frag1.highFivesGuys();
	std::cout << std::endl;
	frag2.takeDamage(30);
	frag2.beRepaired(15);
	std::cout << std::endl;
	std::cout << std::endl;
	return (0);
}


