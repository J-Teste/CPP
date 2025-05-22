/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:39:11 by hakgyver          #+#    #+#             */
/*   Updated: 2025/05/22 15:53:11 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../inc/Array.hpp"
#include "../inc/Colors.hpp"
#include "../inc/Iter.hpp"

const char* getColor()
{
	static int index = 0;
	static const char* colors[] = {RED, BRIGHT_RED, YELLOW, GREEN, BLUE, MAGENTA, BRIGHT_MAGENTA};
	const int numColors = sizeof(colors) / sizeof(colors[0]);
	const char* color = colors[index];
	index = (index + 1) % numColors;
	return (color);
}

template<typename T>
void rainbowPrint(const T &x)
{
	std::cout << getColor() << x << RESET << std::endl;
}

void coutprint(std::string s)
{
	std::cout << s << std::endl;
}

int main()
{
	try
	{
		srand(time(0));
		
		coutprint("\n----------- Construction par defaut -----------\n");
		Array<int> a;
		coutprint("Taille de a");
		std::cout << a.size() << std::endl;

		
		coutprint("\n----------- Construction avec size -----------\n");
		Array<int> b(30);
		Array<std::string> s(2);
		s[0] = "Bozo";
		s[1] = "Goofy";
		coutprint("Taille de b");
		std::cout << b.size() << "\n" << std::endl;
		coutprint("Taille de s");
		std::cout << s.size() << "\n" << std::endl;
		for (size_t i = 0; i < b.size(); i++)
			std::cout << b[i] << " " ;
		std::cout << "\n" << std::endl;
		for (size_t i = 0; i < s.size(); i++)
			std::cout << s[i] << " " ;
		std::cout << "\n" << std::endl;
		for (size_t i = 0; i < b.size(); i++)
			b[i] = rand() % 1000;
		for (size_t i = 0; i < b.size(); i++)
			std::cout << b[i] << " " ;
			
		
		coutprint("\n\n----------- Assignation -----------\n");
		a = b;
		for (size_t i = 0; i < a.size(); i++)
		{
			if (a[i] == b[i])
				std::cout << GREEN << a[i] << " " ;
			else
				std::cout << RED << a[i] << " " ;
		}
		std::cout << RESET;


		coutprint("\n\n----------- Copie -----------\n");
		Array<int> c(b);
		for (size_t i = 0; i < c.size(); i++)
		{
			if (c[i] == b[i])
				std::cout << GREEN << c[i] << " " ;
			else
				std::cout << RED << c[i] << " " ;
		}
		std::cout << RESET;

		
		coutprint("\n\n----------- Modifications -----------\n");
		std::cout << "-Avant\n" << std::endl;
		std::cout << "a[0] = " << a[0] << std::endl;
		std::cout << "b[0] = " << b[0] << std::endl;
		std::cout << "c[0] = " << c[0] << std::endl;
		b[0] = rand() % 1000;
		c[0] = rand() % 1000;
		std::cout << "\n-Apres\n" << std::endl;
		std::cout << "a[0] = " << a[0] << std::endl;
		std::cout << "b[0] = " << b[0] << std::endl;
		std::cout << "c[0] = " << c[0] << std::endl;

		
		coutprint("\n---------- 🌈 RAINBOW 🌈 ----------\n");
		iter(a, a.size(), rainbowPrint<int>);
		iter(s, s.size(), rainbowPrint<std::string>);

		
		coutprint("\n----------- Acces hors limites -----------\n");
		std::cout << b[b.size() + 10] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}
