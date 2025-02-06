/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:08:31 by hakgyver          #+#    #+#             */
/*   Updated: 2025/01/30 13:07:21 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
private:
	std::string _type;
public:
	const std::string& getType() const;
	void setType(std::string new_type);
	Weapon(std::string type);
	~Weapon();
};

#endif
