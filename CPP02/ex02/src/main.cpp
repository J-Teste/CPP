/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:10:41 by hakgyver          #+#    #+#             */
/*   Updated: 2025/02/13 12:23:07 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

void testComparisons(const Fixed &a, const Fixed &b) {
    std::cout << "Comparisons between " << a << " and " << b << ":\n";
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;
    std::cout << "-------------------------\n";
}

void testArithmetic(const Fixed &a, const Fixed &b) {
    std::cout << "Arithmetic operations:\n";
    std::cout << "a + b: " << (a + b) << std::endl;
    std::cout << "a - b: " << (a - b) << std::endl;
    std::cout << "a * b: " << (a * b) << std::endl;
    std::cout << "a / b: " << (a / b) << std::endl;
    std::cout << "-------------------------\n";
}

void testIncrements(Fixed &a) {
    std::cout << "Increment / Decrement tests:\n";
    std::cout << "Initial a: " << a << std::endl;
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "--a: " << --a << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "a--: " << a-- << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "-------------------------\n";
}

void testMinMax(const Fixed &a, const Fixed &b) {
    std::cout << "Min/Max tests:\n";
    std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
    std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;
    std::cout << "-------------------------\n";
}

int main() {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << "Initial values:\n";
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "-------------------------\n";

    testComparisons(a, b);
    testArithmetic(a, b);
    testIncrements(a);
    testMinMax(a, b);

    Fixed c(42.42f);
    Fixed d(3);
    
    std::cout << "More tests with different values:\n";
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;
    testComparisons(c, d);
    testArithmetic(c, d);
    testIncrements(c);
    testMinMax(c, d);

    return 0;
}
