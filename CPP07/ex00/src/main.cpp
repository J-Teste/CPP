/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:55:05 by hakgyver          #+#    #+#             */
/*   Updated: 2025/05/20 14:27:28 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Colors.hpp"
#include <iostream>


template<typename T>
void swap(T &i, T &j)
{
	T tmp = i;
	i = j;
	j = tmp;
}

template<typename T>
T min(T &i, T &j)
{
	return(i < j) ? i : j;
}

template<typename T>
T max(T &i, T &j)
{
	return(i > j) ? i : j;
}

int main()
{
	int i1 = 12;
	int i2 = 24;
	float f1 = 543.986;
	float f2 = 73423.22;
	std::string s1 = "Bozo 1";
	std::string s2 = "Bozo 2";
	std::cout << "\n---- Avant le swap ----\n" << std::endl;
	std::cout << "i1 = " << i1 << std::endl;
	std::cout << "i2 = " << i2 << std::endl;
	std::cout << "f1 = " << f1 << std::endl;
	std::cout << "f2 = " << f2 << std::endl;
	std::cout << "s1 = " << s1 << std::endl;
	std::cout << "s2 = " << s2 << std::endl;
	swap(i1, i2);
	swap(f1, f2);
	swap(s1, s2);
	std::cout << "\n---- Apres le swap ----\n" << std::endl;
	std::cout << "i1 = " << i1 << std::endl;
	std::cout << "i2 = " << i2 << std::endl;
	std::cout << "f1 = " << f1 << std::endl;
	std::cout << "f2 = " << f2 << std::endl;
	std::cout << "s1 = " << s1 << std::endl;
	std::cout << "s2 = " << s2 << std::endl;
	
	std::cout << "\n---- Min/Max ----\n" << std::endl;
	std::cout << "i1 = " << i1 << " i2 = " << i2 << std::endl;
	std::cout << "\n";
	std::cout << "Min = " << min(i1, i2) << std::endl;
	std::cout << "Max = " << max(i1, i2) << std::endl;
	std::cout << "\n";
	std::cout << "f1 = " << f1 << " f2 = " << f2 << std::endl;
	std::cout << "\n";
	std::cout << "Min = " << min(f1, f2) << std::endl;
	std::cout << "Max = " << max(f1, f2) << std::endl;
	std::cout << "\n";
	std::cout << "s1 = " << s1 << " s2 = " << s2 << std::endl;
	std::cout << "\n";
	std::cout << "Min = " << min(s1, s2) << std::endl;
	std::cout << "Max = " << max(s1, s2) << std::endl;
	std::cout << "\n";
	return (0);
}
