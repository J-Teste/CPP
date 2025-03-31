/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 11:11:39 by hakgyver          #+#    #+#             */
/*   Updated: 2025/03/31 16:58:06 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Aform;

class Intern
{
private:
	typedef AForm* (*FormCreator)(const std::string&);
	static const std::string Names[3];
	FormCreator Forms[3];
	static std::string toLower(const std::string &str);
	static AForm	*CreatePresidentialPardonForm(const std::string &target);
	static AForm	*CreateRobotomyRequestForm(const std::string &target);
	static AForm	*CreateShrubberyCreationForm(const std::string &target);
public:
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();
	
	AForm *makeForm(const std::string &form, const std::string &target) const;

};

