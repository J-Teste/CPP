/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:32:21 by hakgyver          #+#    #+#             */
/*   Updated: 2025/01/28 11:00:08 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

int main()
{
	PhoneBook	pb;
	
	while (pb.user_input != "EXIT")
	{
		std::cout << "\nWaiting for input ..." << std::endl;
		getline(std::cin, pb.user_input);
		if (std::cin.eof())
			return (0);
		if (pb.user_input == "ADD")
			pb.add_contact();
		else if (pb.user_input == "SEARCH")
		{
			if (pb.is_empty())
				std::cout << "PhoneBook empty , please add contact first." << std::endl;
			else
			{
				pb.display_contacts();
				int index = pb.get_contact_index();
				pb.display_contact_details(index);
			}
		}
	}
}
