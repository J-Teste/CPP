/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:32:47 by hakgyver          #+#    #+#             */
/*   Updated: 2025/01/28 10:57:07 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.hpp"

/* Constructor */

Contact::Contact()
{
}

/* Destructor */

Contact::~Contact()
{
}

/* Setters & Getters */

void	Contact::set_firstname()
{
	std::string buff;
	while (buff.empty())
	{
		std::cout << "Enter Firstname : ";
		getline(std::cin, buff);
	}
	this->_First_name = buff;
}

std::string Contact::get_firstname(void) const
{
	return std::string(this->_First_name);
}

void Contact::set_lastname()
{
	std::string buff;
	while (buff.empty())
	{
		std::cout << "Enter Lastname : ";
		getline(std::cin, buff);
	}
	this->_Last_name = buff;
}

std::string Contact::get_lastname(void) const
{
	return std::string(this->_Last_name);
}

void Contact::set_nickname()
{
	std::string buff;
	while (buff.empty())
	{
		std::cout << "Enter Nickname : ";
		getline(std::cin, buff);
	}
	this->_Nickname = buff;
}

std::string Contact::get_nickname(void) const
{
	return std::string(this->_Nickname);
}

void Contact::set_phone_number()
{
    std::string buff;
	bool	all_num;
    while (true)
    {
		all_num = true;
        std::cout << "Enter Phone number: ";
        getline(std::cin, buff);
		for (size_t i = 0; i < buff.length(); i++)
		{
			if (!isdigit(buff[i]))
            {
                all_num = false;
                break;
            }
		}
		if (!buff.empty() && all_num)
		{
			this->_Phone_number = buff;
			break;
		}
        else
            std::cout << "Invalid phone number. Please enter only numbers.\n";
    }
}

std::string Contact::get_phone_number(void) const
{
	return std::string(this->_Phone_number);
}

void Contact::set_secret()
{
	std::string buff;
	while (buff.empty())
	{
		std::cout << "Enter Darkest secret : ";
		getline(std::cin, buff);
	}
	this->_Darkest_secret = buff;
}

std::string Contact::get_secret(void) const
{
	return std::string(this->_Darkest_secret);
}

/* Tests and displays */

bool Contact::is_empty(void) const
{
    return (this->_First_name.empty() && this->_Last_name.empty() && this->_Nickname.empty());
}

void Contact::display() const
{
		std::cout << "First_name : " << this->_First_name << std::endl;
		std::cout << "Last_name : " << this->_Last_name << std::endl;
		std::cout << "Nickname : " << this->_Nickname << std::endl;
		std::cout << "Phone_Number : " << this->_Phone_number << std::endl;
		std::cout << "Darkest_secret : " << this->_Darkest_secret << std::endl;
}
