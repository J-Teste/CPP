/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:45:42 by hakgyver          #+#    #+#             */
/*   Updated: 2025/03/20 23:47:27 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"

void sep(const std::string& s) 
{
	std::cout << "\n===== " << s << " =====\n";
}

int main()
{
	const int size = 10;
	Animal* animals[size];

	sep("Création d'animaux");
	for (int i = 0; i < size / 2; i++)
		animals[i] = new Dog();
	for (int i = size / 2; i < size; i++)
		animals[i] = new Cat();
	sep("Vérification des types");
	for (int i = 0; i < size; i++)
		std::cout << "Type de animal[" << i << "]: " << animals[i]->getType() << std::endl;
	sep("Test des sons (polymorphisme)");
	for (int i = 0; i < size; i++)
		animals[i]->makeSound();
	sep("Test de destruction");
	for (int i = 0; i < size; i++)
		delete animals[i];
	return (0);
}

