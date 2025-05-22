/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:39:11 by hakgyver          #+#    #+#             */
/*   Updated: 2025/05/22 12:12:24 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Iter.hpp"
#include "../inc/Colors.hpp"

void x10(int &i)
{
	i *= 10;
}

template<typename T>
void print(const T &x)
{
	std::cout << x << std::endl;
}

void Hello(std::string &s)
{
	s = "Hello " + s;
}

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

int main()
{
	int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::string arr2[] = {"Bozo", "Goofy", "Winnie"};
	const char arr3[] = {'B', 'o', 'Z', '0'};
	print("\n---------- Tableau de int ----------\n");
	iter(arr1, 10, print<int>);
	iter(arr1, 10, x10);
	print("");
	iter(arr1, 10, print<int>);
	print("\n---------- Tableau de string ----------\n");
	iter(arr2, 3, print<std::string>);
	print("");
	iter(arr2, 3, Hello);
	iter(arr2, 3, print<std::string>);
	print("\n---------- Tableau de char const ----------\n");
	iter(arr3, 4, print<char>);
	print("\n---------- 🌈 RAINBOW 🌈----------\n");
	iter(arr1, 10, rainbowPrint<int>);
	iter(arr2, 3, rainbowPrint<std::string>);
	iter(arr3, 4, rainbowPrint<char>);
	return 0;
}
