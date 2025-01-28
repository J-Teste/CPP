/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:12:37 by hakgyver          #+#    #+#             */
/*   Updated: 2025/01/28 10:55:49 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define  CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
private:
	std::string _First_name;
	std::string _Last_name;
	std::string _Nickname;
	std::string _Phone_number;
	std::string _Darkest_secret;
	
public:

	bool	is_empty(void) const;
	
	void		set_firstname(void);
	std::string get_firstname(void) const;
	
	void		set_lastname(void);
	std::string get_lastname(void) const;
	
	void		set_nickname(void);
	std::string get_nickname(void) const;
	
	void		set_phone_number(void);
	std::string get_phone_number(void) const;
	
	void		set_secret(void);
	std::string get_secret(void) const;

	void		display(void) const;
	Contact();
	~Contact();
};

#endif