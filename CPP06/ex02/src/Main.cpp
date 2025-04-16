/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 04:26:58 by hakgyver          #+#    #+#             */
/*   Updated: 2025/04/16 05:27:26 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include "../inc/Colors.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base *generate(void)
{
	int rng = rand() % 3;
	if (rng == 0)
	{
		std::cout << "A" << std::endl;
		return (new A());
	}
	if (rng == 1)
	{
		std::cout << "B" << std::endl;
		return (new B());
	}
	else
	{
		std::cout << "C" << std::endl;
		return (new C());
	}
}

void identify(Base* p) 
{
    if (dynamic_cast<A*>(p)) 
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

void identify(Base& p) 
{
    if (dynamic_cast<A*>(&p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(&p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(&p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

int main()
{
	srand(time(0));
	std::cout << YELLOW << "Objet cree\n" << RESET << "Type : ";
	Base *obj = generate();
	std::cout << YELLOW << "Identification par pointeur\n" << RESET << "Type : ";
	identify(obj);
	std::cout << YELLOW << "Identification par reference\n" << RESET  << "Type : ";
	identify(*obj);
	return (0);
}
