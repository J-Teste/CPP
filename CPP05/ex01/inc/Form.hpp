/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:34:14 by hakgyver          #+#    #+#             */
/*   Updated: 2025/03/27 15:39:45 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Colors.hpp"
#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string  _name;
	bool _is_signed;
	const int _toSign;
	const int _toExecute;
public:
	Form();
	Form(const std::string name, const int toSign, const int toExecute);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();

	std::string getName() const;
	bool getIfSigned() const;
	int getToSign() const;
	int getToExecute() const;

	void beSigned(const Bureaucrat &b);

	class GradeTooHighException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	
	class GradeTooLowException : public std::exception
	{
		public:
			const char *what() const throw();
	};

};

std::ostream &operator<<(std::ostream &os, const Form f);





#endif