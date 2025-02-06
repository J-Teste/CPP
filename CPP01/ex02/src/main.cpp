/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:19:54 by hakgyver          #+#    #+#             */
/*   Updated: 2025/01/30 12:04:35 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
	std::string s = "HI THIS IS BRAIN";
	std::string &stringREF = s;
	std::string *stringPTR = &s;
	std::cout << "\nString address : " << &s << std::endl;
	std::cout << "Ref address : " << &stringREF << std::endl;
	std::cout << "Ptr address : " << stringPTR << std::endl;
	std::cout << "\nString value : " << s << std::endl;
	std::cout << "Ref value : " << stringREF << std::endl;
	std::cout << "Ptr value : " << *stringPTR << std::endl;
	return (0);
}
