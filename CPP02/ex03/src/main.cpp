/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:10:41 by hakgyver          #+#    #+#             */
/*   Updated: 2025/02/24 12:00:08 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

int main() {
    Point a1(0.0f, 0.0f);
    Point b1(5.0f, 0.0f);
    Point c1(2.5f, 5.0f);
    Point p1(2.5f, 2.0f);
    if (bsp(a1, b1, c1, p1))
        std::cout << "\033[32mLe point est dans le triangle.\033[0m" << std::endl;
    else
        std::cout << "\033[31mLe point est hors du triangle.\033[0m" << std::endl;
		
    Point a2(-3.0f, -1.0f);
    Point b2(4.0f, 2.0f);
    Point c2(1.0f, 6.0f);
    Point p2(0.0f, 3.0f);
    if (bsp(a2, b2, c2, p2))
        std::cout << "\033[32mLe point est dans le triangle.\033[0m" << std::endl;
    else
        std::cout << "\033[31mLe point est hors du triangle.\033[0m" << std::endl;

    Point a3(1.0f, 1.0f);
    Point b3(4.0f, 1.0f);
    Point c3(2.5f, 4.0f);
    Point p3(5.0f, 5.0f);
    if (bsp(a3, b3, c3, p3))
        std::cout << "\033[32mLe point est dans le triangle.\033[0m" << std::endl;
    else
        std::cout << "\033[31mLe point est hors du triangle.\033[0m" << std::endl;
    
    return 0;
}


