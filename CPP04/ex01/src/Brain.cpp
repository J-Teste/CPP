/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:37:22 by hakgyver          #+#    #+#             */
/*   Updated: 2025/03/20 22:41:20 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

Brain::Brain()
{
	for (size_t i = 0; i < 100; i++) 
	{
        std::ostringstream oss;
        oss << i;
        this->_ideas[i] = "Idea_" + oss.str();
    }
	std::cout << BRIGHT_GREEN << "Brain created" << RESET << std::endl;
}

Brain::Brain(const Brain &other)
{
	for (size_t i = 0; i < 100; i++)
		this->_ideas[i] = other._ideas[i];
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (size_t i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << BRIGHT_RED << "Brain deleted" << RESET << std::endl;
}
