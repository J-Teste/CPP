/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:45:42 by hakgyver          #+#    #+#             */
/*   Updated: 2025/03/20 23:49:05 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongCat.hpp"

void sep(const std::string& s) 
{
	std::cout << "\n===== " << s << " =====\n";
}

int main()
{
	sep("Création d'animaux");
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	sep("Vérification des types");
	std::cout << "Type de dog: " << dog->getType() << std::endl;
	std::cout << "Type de cat: " << cat->getType() << std::endl;
	sep("Test des sons (polymorphisme)");
	cat->makeSound();
	dog->makeSound();
	meta->makeSound();
	sep("Test de destruction");
	delete meta;
	delete dog;
	delete cat;
	sep("Test avec WrongAnimal et WrongCat");
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << "Type de wrongCat: " << wrongCat->getType() << std::endl;
	wrongCat->makeSound();
	wrongMeta->makeSound();
	sep("Destruction de WrongAnimal et WrongCat");
	delete wrongMeta;
	delete wrongCat;
	sep("Test sans polymorphisme");
	WrongCat wc;
	std::cout << "Type de wc: " << wc.getType() << std::endl;
	wc.makeSound();
	return(0);
}
