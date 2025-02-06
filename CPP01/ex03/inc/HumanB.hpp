/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:08:58 by hakgyver          #+#    #+#             */
/*   Updated: 2025/01/30 13:23:25 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include "./Weapon.hpp"

class HumanB
{
private:
	std::string _name;
	Weapon *_weapon;
public:
	HumanB(std::string name);
	~HumanB();
	void attack() const;
	void setWeapon(Weapon& weapon);
};

#endif
