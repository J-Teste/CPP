/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:39:11 by hakgyver          #+#    #+#             */
/*   Updated: 2025/05/23 13:51:53 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/easyfind.hpp"

int main()
{
	std::vector<int>	v;

	for (int i = 0; i < 10; i++)
		v.push_back(i * 2);

	try
	{
		std::vector<int>::iterator it = easyfind(v, 6);
		std::cout << "Found value : " << *it << std::endl;
	} 
	catch (std::exception& e) 
	{
		std::cerr << e.what() << std::endl;
	}
	try 
	{
		std::vector<int>::iterator it = easyfind(v, 7);
		std::cout << "Found value: " << *it << std::endl;
	} 
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
