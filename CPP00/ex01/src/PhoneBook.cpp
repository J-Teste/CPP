/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:44:22 by hakgyver          #+#    #+#             */
/*   Updated: 2025/01/28 10:59:09 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

PhoneBook::PhoneBook() : _count(0)
{
	std::cout << "You can \"ADD\" up to 8 contacts, \"SEARCH\" them or \"EXIT\"" << std::endl;
}

PhoneBook::~PhoneBook()
{
}
/* For the "ADD" cmd */

void PhoneBook::add_contact(void)
{
	static bool	is_full = false;
	
	if (this->_count == 0 && is_full)
    {
        std::string user_input;
        std::cout << "PhoneBook full. Adding a new contact will overwrite the oldest." << std::endl;
        while (true)
        {
            std::cout << "Continue? Type 'yes' or 'no': ";
            std::getline(std::cin, user_input);
			for (size_t i = 0; i < user_input.length(); i++)
				user_input[i] = std::tolower(user_input[i]);
            if (user_input == "yes")
            {
                this->_count = 0;
                break;
            }
            else if (user_input == "no")
                return;
            else
                std::cout << "Invalid input. Please type 'yes' or 'no'." << std::endl;
        }
	}
	
	this->contacts[_count].set_firstname();
	this->contacts[_count].set_lastname();
	this->contacts[_count].set_nickname();
	this->contacts[_count].set_phone_number();
	this->contacts[_count].set_secret();
	
	this->_count = (this->_count + 1) % MAX_CONTACT;
	if (this->_count == 0)
		is_full = true;
}

/* For the "SEARCH" cmd */

std::string PhoneBook::format_column(std::string s)
{
	if (s.length() > 10)
		return(s.substr(0,9) + ".");
	return (std::string(10 - s.length(), ' ') + s);
}

void PhoneBook::display_contacts(void)
{
	std::cout << std::setw(10) << "index" << "|"
              << std::setw(10) << "first name" << "|"
              << std::setw(10) << "last name" << "|"
              << std::setw(10) << "nickname" << std::endl;
for (int i = 0; i < MAX_CONTACT; i++)
{
	if (!contacts[i].is_empty())
        {
            std::cout << std::setw(10) << i + 1 << "|"
                      << this->format_column(contacts[i].get_firstname()) << "|"
                      << this->format_column(contacts[i].get_lastname()) << "|"
                      << this->format_column(contacts[i].get_nickname()) << std::endl;
        }
}
}

int PhoneBook::get_contact_index()
{
    std::string input;
    int index;

    while (true)
    {
		std::getline(std::cin, input);
		while (input.empty())
		{
			std::cout << "Enter the index of the contact to display: ";
			std::getline(std::cin, input);
		}
        bool is_num = true;
		char c;
		for (size_t i = 0; i < input.length(); i++)
		{
			c = input[i];
			if (std::isdigit(c) == false)
				is_num = false;
		}
        if (is_num)
        {
            index = std::stoi(input);
			index--;
            if (index >= 0 && index < MAX_CONTACT && !this->contacts[index].is_empty())
                return (index);
        }
        std::cout << "Invalid index. Please enter a number between 1 and "
				  << MAX_CONTACT
				  << ". And make sure the contact exists." << std::endl;
    }
}

void PhoneBook::display_contact_details(int index) const
{
	this->contacts[index].display();
}

bool PhoneBook::is_empty(void) const
{
    return (this->contacts[0].is_empty());
}

