/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:16:24 by hakgyver          #+#    #+#             */
/*   Updated: 2025/01/29 17:08:19 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <new>

class Zombie
{
private:
	std::string	_name;
public:
	void announce( void );
	Zombie(void);
	Zombie(std::string name);
	~Zombie();
	void setName(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif
