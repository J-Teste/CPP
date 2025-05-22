/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:44:16 by hakgyver          #+#    #+#             */
/*   Updated: 2025/05/22 13:57:57 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Array.hpp"

template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {};

template<typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]), _size(n) {}
 
template <typename T>
size_t Array<T>::size() const
{
	return(this->_size);
}

template<typename T>
Array<T>::Array(const Array & other) : _data(new T[other._size]), _size(other._size)
{
	for (size_t i = 0; i < _size; i++)
		this->_data[i] = other._data[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete[] _data;
		_size = other._size;
		_data = new T[_size];
		for (size_t i = 0; i < _size; i++)
			_data[i] = other._data[i];
	}
	
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] _data;
}

