/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:26:43 by hakgyver          #+#    #+#             */
/*   Updated: 2025/03/20 23:07:44 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"

class Dog : public AAnimal
{
	private:
		Brain *brain;
	public:
		Dog();
		Dog(const Dog &other);
		~Dog();
		Dog &operator=(const Dog &other);
		void makeSound() const;
};

#endif