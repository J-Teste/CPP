/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:00:56 by hakgyver          #+#    #+#             */
/*   Updated: 2025/06/13 13:05:50 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	MutantStack() : std::stack<T>() 
	{
	}
	MutantStack(const MutantStack& other) : std::stack<T>(other) 
	{
	}
	MutantStack& operator=(const MutantStack& other) 
	{
		std::stack<T>::operator=(other);
		return (*this);
	}
	~MutantStack()
	{
	}
	
	iterator begin() 
	{
		return (this->c.begin()); 
	}
	
	iterator end() 
	{
		return (this->c.end()); 
	}
	
	reverse_iterator rbegin()
	{
		return (this->c.rbegin());
	}
	
	reverse_iterator rend()
	{
		return (this->c.rend());
	}
};



#endif