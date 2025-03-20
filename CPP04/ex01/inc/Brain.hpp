/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:24:57 by hakgyver          #+#    #+#             */
/*   Updated: 2025/03/20 17:59:01 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>
#include <sstream>
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