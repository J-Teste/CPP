#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void	run(int argc, char **argv);

	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;

		static bool			parseInt(const std::string &s, int &out);
		static void			printBefore(const std::vector<int> &v);
		static void			printAfter(const std::vector<int> &v);
		static double		elapsedUs(clock_t start, clock_t end);
		static void			fordJohnsonVector(std::vector<int> &a);
		static void			fordJohnsonDeque(std::deque<int> &a);
		static void			insertBoundedVector(std::vector<int> &mainChain, int value, int bound);
		static void			insertBoundedDeque(std::deque<int> &mainChain, int value, int bound);
};

#endif
