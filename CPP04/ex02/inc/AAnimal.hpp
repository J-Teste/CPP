/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:30:07 by hakgyver          #+#    #+#             */
/*   Updated: 2025/03/16 18:36:57 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Colors.hpp"
#include "Brain.hpp"

class Animal
{
	protected:
		std::string _type;
	public:
		virtual void makeSound() const = 0;
		virtual std::string getType() const = 0;
		virtual ~Animal();
};

#endif
