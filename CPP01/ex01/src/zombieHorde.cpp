/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:13:56 by hakgyver          #+#    #+#             */
/*   Updated: 2025/01/29 17:09:57 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie	*Leader = new Zombie[N];
	for (int i = 0; i < N; i++)
		Leader[i].setName(name);
	return(Leader);
}
