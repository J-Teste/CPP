/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:39:11 by hakgyver          #+#    #+#             */
/*   Updated: 2025/06/13 13:29:09 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <ctime>
#include <list>

int main()
{
	std::cout << "\n------------------- MUTANTSTACK -------------------\n" << std::endl;
	MutantStack<char> m1;
	std::string c1 = "...laer si namtaB";
	for (size_t i = 0; i < c1.size(); i++)
		m1.push(c1[i]);
	std::cout << "Lecture (begin → end) :\n";
	for (MutantStack<char>::iterator it = m1.begin(); it != m1.end(); ++it)
			std::cout << *it;
	std::cout << "\n" << std::endl;
	std::cout << "Lecture (rbegin → rend) :\n";
	for (MutantStack<char>::reverse_iterator rit = m1.rbegin(); rit != m1.rend(); ++rit)
		std::cout << *rit;


	std::cout << "\n------------------- LIST -------------------\n" << std::endl;
		std::list<char> l1;
	for (size_t i = 0; i < c1.size(); i++)
		l1.push_back(c1[i]);

	std::cout << "\nLecture (begin → end) :\n";
	for (std::list<char>::iterator it = l1.begin(); it != l1.end(); ++it)
		std::cout << *it;
	std::cout << "\n" << std::endl;

	std::cout << "Lecture (rbegin → rend) :\n";
	for (std::list<char>::reverse_iterator rit = l1.rbegin(); rit != l1.rend(); ++rit)
		std::cout << *rit;
	std::cout << "\n" << std::endl;

	return (0);
}





// int main()
// {
// MutantStack<int> mstack;
// mstack.push(5);
// mstack.push(17);
// std::cout << mstack.top() << std::endl;
// mstack.pop();
// std::cout << mstack.size() << std::endl;
// mstack.push(3);
// mstack.push(5);
// mstack.push(737);
// mstack.push(0);
// MutantStack<int>::iterator it = mstack.begin();
// MutantStack<int>::iterator ite = mstack.end();
// ++it;
// --it;
// while (it != ite)
// {
// std::cout << *it << std::endl;
// ++it;
// }
// std::stack<int> s(mstack);
// return 0;
// }