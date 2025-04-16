/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 03:40:11 by hakgyver          #+#    #+#             */
/*   Updated: 2025/04/16 04:22:21 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"


void printData(std::string const &title, Data const *data) 
{
	std::cout << YELLOW << title << " : " << RESET << data << std::endl;
	std::cout << YELLOW << "  - n : " << RESET << data->n << std::endl;
	std::cout << YELLOW << "  - s : " << RESET << data->s << std::endl;
	std::cout << YELLOW << "  - b : " << RESET << (data->b ? "true" : "false") << std::endl;
	std::cout << YELLOW << "  - c : '" << RESET << data->c << "'" << std::endl;
}

int main() 
{
	Data original;
	original.n = 1111111111;
	original.s = "Batman is real !";
	original.b = true;
	original.c = '*';
	std::cout << YELLOW << "\nContenu initial de la structure :\n" << RESET;
	printData("Original", &original);
	uintptr_t raw = Serializer::serialize(&original);
	std::cout << YELLOW << "Valeur brute (uintptr_t) : " << RESET << raw << std::endl;
	Data *converted = Serializer::deserialize(raw);
	std::cout <<  YELLOW << "\nComparaison des pointeurs :\n" << RESET;
	std::cout << YELLOW << "Original     : " << RESET << &original << std::endl;
	std::cout << YELLOW << "Désérialisé  : " << RESET << converted << std::endl;
	if (converted == &original)
		std::cout << GREEN << "Les pointeurs sont identiques\n" << RESET;
	else
		std::cout << RED << "Les pointeurs ne sont pas identiques !\n" << RESET;
	std::cout << YELLOW << "\nContenu récupéré après désérialisation :\n" << RESET;
	printData("Converted", converted);
	return 0;
}