/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:45:42 by hakgyver          #+#    #+#             */
/*   Updated: 2025/03/20 23:37:31 by hakgyver         ###   ########.fr       */
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
	sep("Création d'animaux");
	// const AAnimal* meta = new AAnimal();
	const AAnimal* dog = new Dog();
	const AAnimal* cat = new Cat();
	sep("Vérification des types");
	std::cout << "Type de dog: " << dog->getType() << std::endl;
	std::cout << "Type de cat: " << cat->getType() << std::endl;
	sep("Test des sons (polymorphisme)");
	cat->makeSound();
	dog->makeSound();
	sep("Test de destruction");
	delete dog;
	delete cat;
	sep("Test sans polymorphisme");
	Dog d;
	std::cout << "Type de d: " << d.getType() << std::endl;
	d.makeSound();
	return 0;
}