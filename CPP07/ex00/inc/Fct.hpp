/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:01:50 by hakgyver          #+#    #+#             */
/*   Updated: 2025/05/20 16:02:22 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FCT_HPP
#define FCT_HPP

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


#endif