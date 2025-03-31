/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:34:26 by hakgyver          #+#    #+#             */
/*   Updated: 2025/03/27 15:56:10 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

AForm::AForm() : _name("Wedding Contract"), _is_signed(false), _toSign(50), _toExecute(50)
{
	std::cout << GREEN << "Form \"" << RESET << _name << GREEN << "\" has been created. A grade of " << RESET << _toSign << GREEN << " is required to sign it and a grade of " << RESET << _toExecute << GREEN << " is required to execute it. (default constructor)" << std::endl;
}

AForm::AForm(const std::string name, const int toSign, const int toExecute) : _name(name), _is_signed(false), _toSign(toSign), _toExecute(toExecute)
{
	if (toSign < 1 || toExecute < 1)
		throw GradeTooHighException();
	else if (toSign > 150 || toExecute > 150)
		throw GradeTooLowException();
	else 
		std::cout << GREEN << "Form \"" << RESET << _name << GREEN << "\" has been created. A grade of " << RESET << _toSign << GREEN << " is required to sign it and a grade of " << RESET << _toExecute << GREEN << " is required to execute it. (with parameter constructor)" << std::endl;
}

AForm::AForm(const AForm &other): _name(other._name), _is_signed(other._is_signed), _toSign(other._toSign), _toExecute(other._toExecute)
{
	std::cout << GREEN << "Form \"" << RESET << _name << GREEN << "\" has been created. A grade of " << RESET << _toSign << GREEN << " is required to sign it and a grade of " << RESET << _toExecute << GREEN << " is required to execute it. (copy constructor)" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->_is_signed = other._is_signed;
	return(*this);
}

AForm::~AForm()
{
	std::cout << RED << "Form " << RESET << _name << RED << " finished in the document shredder." << std::endl; 
}

std::string AForm::getName() const
{
	return std::string(_name);
}

bool AForm::getIfSigned() const
{
	return (_is_signed);
}

int AForm::getToSign() const
{
	return (_toSign);
}

int AForm::getToExecute() const
{
	return (_toExecute);
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->_toSign)
		throw GradeTooLowException();
	this->_is_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high !");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low !");
}

const char *AForm::NotSignedException::what() const throw()
{
	return ("Form must be signed before execution !");
}
std::ostream &operator<<(std::ostream &os, const AForm &f)
{
	os << YELLOW <<  "Form : " << RESET << f.getName() << YELLOW << ".  A grade of " << RESET << f.getToSign() << YELLOW << " is required to sign it and a grade of " << RESET << f.getToExecute() << YELLOW << " is required to execute it." << RESET << std::endl;
	if (f.getIfSigned() == true)
		os << BRIGHT_GREEN << "This form is already signed." << RESET << std::endl;
	else
		os << BRIGHT_RED << "This form is not signed yet." << RESET << std::endl;
	return (os);
}

void AForm::checkRequirements(Bureaucrat const &executor) const
{
	if (this->_is_signed == false)
		throw NotSignedException();
	if (executor.getGrade() > this->_toExecute)
		throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const &executor) const
{
	try
	{
		this->checkRequirements(executor);
		this->executeAction();
		std::cout << executor.getName() << GREEN << " executed " << RESET << this->_name << "." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << executor.getName() <<  BRIGHT_RED << " couldn't execute " << RESET << this->_name << " because ";
		std::cerr << RED << e.what() << RESET << '\n';
	}
}

