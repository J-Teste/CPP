/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:58:23 by hakgyver          #+#    #+#             */
/*   Updated: 2025/05/24 16:17:53 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Intern.hpp"

void sep(std::string s)
{
    std::cout << "\n\n----------- " << s << " -----------\n";
}

int main()
{
	sep("Cas 1 : L'Intern crée un ShrubberyCreationForm, signé et exécuté par un Bureaucrate");
	try
	{
		Intern intern;
		Bureaucrat b1("Bozo", 1);
		AForm* f1 = intern.makeForm("shrubbery creation", "home");
		if (!f1)
			throw std::runtime_error("L'Intern n'a pas pu créer le formulaire.");
		std::cout << *f1;
		b1.signForm(*f1);
		b1.executeForm(*f1);
		delete f1;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	sep("Cas 2 : L'Intern crée un formulaire inconnu");
	try
	{
		Intern intern;
		AForm* f2 = intern.makeForm("formulaire inconnu", "target");
		if (!f2)
			throw std::runtime_error("L'Intern n'a pas pu créer le formulaire.");
		delete f2;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	sep("Cas 3 : Bureaucrate tente de signer un formulaire sans le niveau requis");
	try
	{
		Intern intern;
		Bureaucrat b2("Bozo", 150);
		AForm* f3 = intern.makeForm("robotomy request", "target");
		if (!f3)
			throw std::runtime_error("L'Intern n'a pas pu créer le formulaire.");
		std::cout << *f3;
		b2.signForm(*f3);
		delete f3;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	sep("Cas 4 : Bureaucrate exécute un formulaire non signé");
	try
	{
		Intern intern;
		Bureaucrat b3("Bozo", 45);
		AForm* f4 = intern.makeForm("robotomy request", "target");
		if (!f4)
			throw std::runtime_error("L'Intern n'a pas pu créer le formulaire.");
		std::cout << *f4;
		b3.executeForm(*f4);
		delete f4;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	sep("Cas 5 : Bureaucrate signe et exécute PresidentialPardonForm");
	try
	{
		Intern intern;
		Bureaucrat b4("Bozo", 1);
		AForm* f5 = intern.makeForm("presidential pardon", "Zaphod");
		if (!f5)
			throw std::runtime_error("L'Intern n'a pas pu créer le formulaire.");
		std::cout << *f5;
		b4.signForm(*f5);
		b4.executeForm(*f5);
		delete f5;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	sep("Cas 6 : Bureaucrate signe et exécute RobotomyRequestForm");
	try
	{
		Intern intern;
		Bureaucrat b5("Bozo", 1);
		AForm* f6 = intern.makeForm("robotomy request", "subject");
		if (!f6)
			throw std::runtime_error("L'Intern n'a pas pu créer le formulaire.");
		std::cout << *f6;
		b5.signForm(*f6);
		b5.executeForm(*f6);
		delete f6;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
