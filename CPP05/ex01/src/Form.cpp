/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:34:26 by hakgyver          #+#    #+#             */
/*   Updated: 2025/03/27 15:56:10 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

Form::Form():_name("Wedding Contract"), _is_signed(false), _toSign(50), _toExecute(50)
{
	std::cout << GREEN << "Form \"" << RESET << _name << GREEN << "\" has been created. A grade of " << RESET << _toSign << GREEN << " is required to sign it and a grade of " << RESET << _toExecute << GREEN << " is required to execute it. (default constructor)" << std::endl;
}

Form::Form(const std::string name, const int toSign, const int toExecute) : _name(name), _is_signed(false), _toSign(toSign), _toExecute(toExecute)
{
	if (toSign < 1 || toExecute < 1)
		throw GradeTooHighException();
	else if (toSign > 150 || toExecute > 150)
		throw GradeTooLowException();
	else 
		std::cout << GREEN << "Form \"" << RESET << _name << GREEN << "\" has been created. A grade of " << RESET << _toSign << GREEN << " is required to sign it and a grade of " << RESET << _toExecute << GREEN << " is required to execute it. (with parameter constructor)" << std::endl;
}

Form::Form(const Form &other): _name(other._name), _is_signed(other._is_signed), _toSign(other._toSign), _toExecute(other._toExecute)
{
	std::cout << GREEN << "Form \"" << RESET << _name << GREEN << "\" has been created. A grade of " << RESET << _toSign << GREEN << " is required to sign it and a grade of " << RESET << _toExecute << GREEN << " is required to execute it. (copy constructor)" << std::endl;
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		this->_is_signed = other._is_signed;
	return(*this);
}

Form::~Form()
{
	std::cout << RED << "Form \"" << RESET << _name << RED << "\" finished in the document shredder." << std::endl; 
}

std::string Form::getName() const
{
	return std::string(_name);
}

bool Form::getIfSigned() const
{
	return (_is_signed);
}

int Form::getToSign() const
{
	return (_toSign);
}

int Form::getToExecute() const
{
	return (_toExecute);
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->_toSign)
		throw GradeTooLowException();
	this->_is_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high !");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low !");
}

std::ostream &operator<<(std::ostream &os, const Form f)
{
	os << YELLOW <<  "Form : " << RESET << f.getName() << YELLOW << ".  A grade of " << RESET << f.getToSign() << YELLOW << " is required to sign it and a grade of " << RESET << f.getToExecute() << YELLOW << " is required to execute it.";
	if (f.getIfSigned() == true)
		os << BRIGHT_GREEN << " This form is already signed." << std::endl;
	else
		os << BRIGHT_RED << " This form is not signed yet." << std::endl;
	return (os);
}