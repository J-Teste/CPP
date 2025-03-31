/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:58:23 by hakgyver          #+#    #+#             */
/*   Updated: 2025/03/29 10:25:52 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

void sep(std::string s)
{
    std::cout << "\n\n----------- " << s << " -----------\n";
}

int main()
{
    sep("Cas 1 : Bureaucrate signe et exécute ShrubberyCreationForm");
    try
    {
        Bureaucrat b1("Bozo", 1);
        ShrubberyCreationForm f1("home");
        std::cout << f1;
        b1.signForm(f1);
        b1.executeForm(f1);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    sep("Cas 2 : Bureaucrate tente de signer un formulaire sans le niveau requis");
    try
    {
        Bureaucrat b2("Bozo", 150);
        RobotomyRequestForm f2("target");
        std::cout << f2;
        b2.signForm(f2);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    sep("Cas 3 : Bureaucrate exécute un formulaire non signé");
    try
    {
        Bureaucrat b3("Bozo", 45);
        RobotomyRequestForm f3("target");
        std::cout << f3;
        b3.executeForm(f3);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    sep("Cas 4 : Bureaucrate signe et exécute PresidentialPardonForm");
    try
    {
        Bureaucrat b4("Bozo", 1);
        PresidentialPardonForm f4("Zaphod");
        std::cout << f4;
        b4.signForm(f4);
        b4.executeForm(f4);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    sep("Cas 5 : Bureaucrate signe et exécute RobotomyRequestForm");
    try
    {
        Bureaucrat b5("Bozo", 1);
        RobotomyRequestForm f5("subject");
        std::cout << f5;
        b5.signForm(f5);
        b5.executeForm(f5);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return (0);
}
