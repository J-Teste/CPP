/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:13:51 by hakgyver          #+#    #+#             */
/*   Updated: 2025/01/29 16:52:13 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int main()
{
	int i = 42;
	Zombie *leader = zombieHorde(i, "Bob");
	for (int j = 0; j < i; j++)
		leader[j].announce();
	delete[] leader;
	return (0);
}
