/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:05:54 by hakgyver          #+#    #+#             */
/*   Updated: 2025/05/26 11:48:27 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <algorithm>
#include <vector>



class Span
{
private:
	std::vector<int> _data;
	unsigned int _capacity;
public:
	Span();
	Span(unsigned int);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber();
	size_t shortestSpan(); 
};

#endif