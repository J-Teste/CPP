/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:34:14 by hakgyver          #+#    #+#             */
/*   Updated: 2025/03/27 15:39:45 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Colors.hpp"
#include "Bureaucrat.hpp"

class AForm
{
protected:
	virtual void executeAction() const = 0;
private:
	const std::string  _name;
	bool _is_signed;
	const int _toSign;
	const int _toExecute;
	void checkRequirements(Bureaucrat const &executor) const;
public:
	AForm();
	AForm(const std::string name, const int toSign, const int toExecute);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm();
	std::string getName() const;
	bool getIfSigned() const;
	int getToSign() const;
	int getToExecute() const;
	void beSigned(const Bureaucrat &b);
	void execute(Bureaucrat const &executor) const;

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
	class NotSignedException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	
};

std::ostream &operator<<(std::ostream &os, const AForm &f);





#endif