/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:33:13 by hakgyver          #+#    #+#             */
/*   Updated: 2025/01/29 15:11:24 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int main()
{
	Zombie	*Al;
	Al = newZombie("Al");
	Al->announce();
	randomChump("Bob");
	delete Al;
	return (0);
}
