/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:55:41 by hakgyver          #+#    #+#             */
/*   Updated: 2025/01/29 15:11:55 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>


class Zombie
{
private:
	std::string	_name;
public:
	void announce( void );
	Zombie(std::string name);
	~Zombie();
};

Zombie* newZombie(std::string name);
void randomChump( std::string name );

#endif
