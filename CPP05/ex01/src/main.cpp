/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:58:23 by hakgyver          #+#    #+#             */
/*   Updated: 2025/03/27 15:37:36 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

void sep(std::string s)
{
    std::cout << "\n\n----------- " << s << " -----------\n";
}

int main()
{
    sep("Cas 1 : Signature impossible (grade trop bas)");
    try
    {
        Bureaucrat b1("Bozo", 50);
        Form f1("Contrat", 10, 20);
        std::cout << f1;
        b1.signForm(f1);
        std::cout << f1;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    sep("Cas 2 : Signature réussie");
    try
    {
        Bureaucrat b2("Alice", 5);
        Form f2("Permission", 10, 20);
        std::cout << f2;
        b2.signForm(f2);
        std::cout << f2;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
