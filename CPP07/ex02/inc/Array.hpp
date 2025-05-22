/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:26:13 by hakgyver          #+#    #+#             */
/*   Updated: 2025/05/22 13:57:25 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <cstddef>

template<typename T>
class Array
{
private:
	T *_data;
	unsigned int _size;
public:
	Array();
	Array(unsigned int n);
	Array(const Array &other);
	Array& operator=(const Array &other);
	~Array();
	
	T& operator[](std::size_t index)
	{
		if (index >= _size)
			throw std::out_of_range("Index out of range.");
		return(_data[index]);
	}
	const T& operator[](std::size_t index) const
	{
		if (index >= _size)
			throw std::out_of_range("Index out of range.");
		return(_data[index]);
	}
	
	std::size_t size() const;
};



#include "../src/Array.tpp"

#endif


