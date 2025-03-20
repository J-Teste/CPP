/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:24:57 by hakgyver          #+#    #+#             */
/*   Updated: 2025/03/19 09:35:29 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include "Colors.hpp"

class Brain
{
private:
	std::string _ideas[100];
public:
	Brain();
	Brain(const Brain &other);
	Brain operator=(const Brain &other);
	~Brain();
};

#endif