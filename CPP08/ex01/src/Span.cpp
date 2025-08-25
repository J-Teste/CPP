#include "Span.hpp"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:05:58 by hakgyver          #+#    #+#             */
/*   Updated: 2025/05/23 14:05:59 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


Span::Span(unsigned int n) : _capacity(n)
{
}

Span::Span(const Span &other) : _data(other._data), _capacity(other._capacity)
{
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_data = other._data;
		_capacity = other._capacity;
	}
	return (*this);
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
	if (_data.size() >= _capacity)
		throw std::runtime_error("Span is already full");
	_data.push_back(n);
}

size_t Span::shortestSpan() const
{
	if (_data.size() < 2)
		throw std::runtime_error("Not enough elements for a span");
	std::vector<int>	tmp = _data;
	std::sort(tmp.begin(), tmp.end());
	int	minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < tmp.size(); ++i) 
	{
		int	span = tmp[i] - tmp[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return (minSpan);
}

int Span::longestSpan() const {
	if (_data.size() < 2)
		throw std::runtime_error("Not enough elements for a span");

	int	minVal = *std::min_element(_data.begin(), _data.end());
	int	maxVal = *std::max_element(_data.begin(), _data.end());

	return (maxVal - minVal);
}


