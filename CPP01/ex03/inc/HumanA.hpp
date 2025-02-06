/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:09:00 by hakgyver          #+#    #+#             */
/*   Updated: 2025/01/30 13:12:49 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include "./Weapon.hpp"

class HumanA
{
private:
	std::string _name;
	Weapon& _weapon;
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void attack() const;
};




#endif
