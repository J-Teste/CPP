/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:21:53 by hakgyver          #+#    #+#             */
/*   Updated: 2025/02/24 11:22:21 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed cp1 = (b.getx() - a.getx()) * (point.gety() - a.gety()) - (b.gety() - a.gety()) * (point.getx() - a.getx());
	Fixed cp2 = (c.getx() - b.getx()) * (point.gety() - b.gety()) - (c.gety() - b.gety()) * (point.getx() - b.getx());
	Fixed cp3 = (a.getx() - c.getx()) * (point.gety() - c.gety()) - (a.gety() - c.gety()) * (point.getx() - c.getx());
 
	if (cp1 == 0 || cp2 == 0 || cp3 == 0)
        return true;
	return ((cp1 > 0 && cp2 > 0 && cp3 > 0) || (cp1 < 0 && cp2 < 0 && cp3 < 0)); 
}