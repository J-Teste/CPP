/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:44:16 by hakgyver          #+#    #+#             */
/*   Updated: 2025/05/22 11:13:29 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstring>

template<typename T, typename F>
void iter(T *arr, size_t len, F fct)
{
	for (size_t i = 0; i < len; i++)
		fct(arr[i]);
}

#endif