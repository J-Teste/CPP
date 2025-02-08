/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:35:23 by hakgyver          #+#    #+#             */
/*   Updated: 2025/02/08 13:56:17 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

int	get_level(std::string const &level)
{
	if (level == "DEBUG")
		return (1);
	else if (level == "INFO")
		return (2);
	else if (level == "WARNING")
		return (3);
	else if (level == "ERROR")
		return (4);
	else
		return (0);
}
int main(int argc, const char** argv)
{
	Harl dull_boy;
	if (argc != 2)
	{
		std::cout << "\nUsage : ./harlFilter <level>\n" << std::endl;
		return (1);
	}
	switch (get_level(argv[1]))
	{
	case 1 :
		dull_boy.complain("DEBUG");
	case 2 :
		dull_boy.complain("INFO");
	case 3 :
		dull_boy.complain("WARNING");
	case 4 :
		dull_boy.complain("ERROR");
		break;
	default:
		std::cout << "\nCannot find the level : " << argv[1] << "\n" << std::endl;
		break;
	}
	return (0);
}
