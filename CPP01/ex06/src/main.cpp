/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:35:23 by hakgyver          #+#    #+#             */
/*   Updated: 2025/02/06 13:29:06 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

int main()
{
	Harl dull_boy;
	std::cout << "\n-- DEBUG LEVEL --" << std::endl;
	dull_boy.complain("DEBUG");
	std::cout << "-- INFO LEVEL --" << std::endl;
	dull_boy.complain("INFO");
	std::cout << "-- WARNING LEVEL --" << std::endl;
	dull_boy.complain("WARNING");
	std::cout << "-- ERROR LEVEL --" << std::endl;
	dull_boy.complain("ERROR");
	return 0;
}
