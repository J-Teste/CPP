/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 21:28:13 by hakgyver          #+#    #+#             */
/*   Updated: 2025/03/27 15:16:43 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Bozo"), _grade(150)
{
	std::cout << GREEN << "A bureaucrat named " << RESET << _name << GREEN << " has been created with a grade of " << RESET << _grade << GREEN << ". (Default constructor)" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
	std::cout << GREEN << "A bureaucrat named " << RESET << _name << GREEN << " has been created with a grade of " << RESET << _grade << GREEN << ". (Name & Grade constructor)" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade)
{
	std::cout << GREEN << "A bureaucrat named " << RESET << _name << GREEN << " has been created with a grade of " << RESET << _grade << GREEN << ". (Copy constructor)" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
		std::cout << GREEN << "A bureaucrat named " << RESET << _name << GREEN << " now have a grade of " << RESET << _grade << GREEN << ". (Operator =)" << std::endl;
	}
	return(*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "A bureaucrat named " << RESET << _name << RED << " has been fired. (Default destructor)" << RESET << std::endl;
}

std::string Bureaucrat::getName() const
{
	return std::string(_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return(os);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high !");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low !");
}
