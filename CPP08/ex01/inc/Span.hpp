/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:05:54 by hakgyver          #+#    #+#             */
/*   Updated: 2025/06/13 11:33:42 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>



class Span
{
private:
	std::vector<int> _data;
	unsigned int _capacity;
public:
	Span(unsigned int n);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber(int n);
	size_t shortestSpan() const;
	int longestSpan() const;

template<typename Iterator>
void addNumber(Iterator begin, Iterator end) 
{
	if (std::distance(begin, end) + _data.size() > _capacity)
		throw std::runtime_error("Not enough space to add range");
	_data.insert(this->_data.end(), begin, end);
}
};

#endif