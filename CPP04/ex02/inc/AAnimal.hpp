/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:30:07 by hakgyver          #+#    #+#             */
/*   Updated: 2025/03/20 18:02:28 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include "Colors.hpp"
#include "Brain.hpp"

class AAnimal
{
	protected:
		std::string _type;
	public:
		AAnimal();
		AAnimal(const AAnimal &other);
		AAnimal &AAnimal::operator=(const AAnimal &other);
		virtual void makeSound() const = 0;
		virtual std::string getType() const = 0;
		virtual ~AAnimal();
};

#endif
