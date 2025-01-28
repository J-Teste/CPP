/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:47:51 by hakgyver          #+#    #+#             */
/*   Updated: 2025/01/28 10:55:22 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <sstream>

#define MAX_CONTACT 8

class PhoneBook
{
private:
	Contact contacts[MAX_CONTACT];
	int		_count;
public:
	int	index;
	std::string user_input;
	bool	is_empty(void) const;
	PhoneBook();
	~PhoneBook();
	std::string	format_column(std::string s);
	int	get_contact_index();
	void add_contact(void);
	void display_contacts(void);
	void display_contact_details(int index) const;
};

#endif