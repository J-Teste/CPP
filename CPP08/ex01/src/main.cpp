/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:39:11 by hakgyver          #+#    #+#             */
/*   Updated: 2025/06/13 11:45:37 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "Colors.hpp"

int main()
{
	Span s = Span(10000);
	Span s1 = Span(1);
	Span s2 = Span(999999);
	std::vector<int> v;
	srand(time(0));
	
	try
	{
		for (size_t i = 0; i < 10000; i++)
			s.addNumber(rand());
		std::cout << "[10000] -> Shortest span : " << s.shortestSpan() << std::endl;
		std::cout << "[10000] -> Longest span : " << s.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		for (size_t i = 0; i < 999999; i++)
			v.push_back(rand());
		s2.addNumber(v.begin(), v.end());
		std::cout << "[999999] with iterators -> Shortest span : " << s2.shortestSpan() << std::endl;
		std::cout << "[999999] with iterators -> Longest span : " << s2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		s.addNumber(rand());
	}
	catch(const std::exception& e)
	{
		std::cerr << RED <<  e.what() << RESET <<  '\n';
	}
	try
	{
		s1.addNumber(rand());
		s1.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED <<  e.what() << RESET <<  '\n';
	}
	try
	{
		s2.addNumber(v.begin(), v.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << RED <<  e.what() << RESET <<  '\n';
	}
	
	return 0;
}
