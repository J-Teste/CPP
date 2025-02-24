/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:24:06 by hakgyver          #+#    #+#             */
/*   Updated: 2025/02/24 11:00:35 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

Point::Point() : _x(0) , _y(0)
{
}
Point::Point(const float x, const float y) : _x(x) , _y(y)
{
}

Point::Point(const Point &other) : _x(other._x), _y(other._y)
{
}
Point& Point::operator=(const Point &other)
{
	(void)other;
	return(*this);
}

Point::~Point()
{
}

Fixed Point::getx() const
{
	return Fixed(_x);
}

Fixed Point::gety() const
{
	return Fixed(_y);
}
