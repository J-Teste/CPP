/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:37:19 by hakgyver          #+#    #+#             */
/*   Updated: 2025/02/06 13:27:19 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

Harl::Harl() 
{
	std::cout << "** Strange mechanical noise and some grumbling **\n" 
			  << "Harl rolls in on his motorized chair to annoy everyone." 
			  << std::endl;
}

Harl::~Harl()
{
	std::cout << "** Strange mechanical noise and some grumbling fade away**\n" 
			  << "Then suddenly, Harl disappears, leaving everyone in peace."
			  << std::endl;
}
void Harl::debug(void)
{
		std::cout << "\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!\n"
			      << std::endl;
}
void Harl::info(void)
{
	std::cout << "\nI cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger!\nIf you did, I wouldn’t be asking for more!\n"
	  		  << std::endl;
}
void Harl::warning(void)
{
	std::cout << "\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n"
	  		  << std::endl;
}
void Harl::error(void)
{
	std::cout << "\nThis is unacceptable!\nI want to speak to the manager now.\n"
	  		  << std::endl;
}

void Harl::complain(std::string level)
{
	std::string const levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*fnct[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	for (size_t i = 0; i < 4; i++)
	{
		if (levels[i] == level)
			(this->*fnct[i])();
	}
}
