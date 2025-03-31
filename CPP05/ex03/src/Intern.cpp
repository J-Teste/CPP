/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 11:11:13 by hakgyver          #+#    #+#             */
/*   Updated: 2025/03/31 16:59:06 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

const std::string Intern::Names[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};


Intern::Intern()
{
	Forms[0] = &Intern::CreatePresidentialPardonForm;
	Forms[1] = &Intern::CreateRobotomyRequestForm;
	Forms[2] = &Intern::CreateShrubberyCreationForm;
	std::cout << GREEN << "An Intern found the coffee machine (default constructor)" << RESET << std::endl;
}

Intern::Intern(const Intern &other)
{
	(void)other;
	Forms[0] = &Intern::CreatePresidentialPardonForm;
	Forms[1] = &Intern::CreateRobotomyRequestForm;
	Forms[2] = &Intern::CreateShrubberyCreationForm;
	std::cout << GREEN << "An Intern found the coffee machine (copy constructor)" << RESET << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{
	std::cout << RED << "An Intern was found dead near the coffee machine (default destructor)" << RESET << std::endl;
}

std::string Intern::toLower(const std::string &str)
{
	std::string lStr = str;
	for (size_t i = 0; i < lStr.length(); i++) 
		lStr[i] = std::tolower(lStr[i]);
	return lStr;
}

AForm *Intern::CreatePresidentialPardonForm(const std::string &target)
{
	return(new PresidentialPardonForm(target));
}

AForm *Intern::CreateRobotomyRequestForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::CreateShrubberyCreationForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(const std::string &form, const std::string &target) const
{
	std::string lForm = toLower(form);
	for (size_t i = 0; i < 3; i++)
	{
		if (lForm == Names[i])
		{
			std::cout << YELLOW << "Intern creats " << RESET << form << YELLOW << "." << RESET << std::endl;
			return ((Forms[i])(target));
 		}
	}
	throw std::invalid_argument("Error: Form \"" + form + "\" not found!");
}