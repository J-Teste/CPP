#include "PmergeMe.hpp"

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <climits>
#include <cerrno>
#include <ctime>
#include <algorithm>

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _deq(other._deq)
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_deq = other._deq;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

bool PmergeMe::parseInt(const std::string &s, int &out)
{
	if (s.empty())
		return (false);
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (false);
	}
	errno = 0;
	long v = std::strtol(s.c_str(), 0, 10);
	if (errno != 0)
		return (false);
	if (v <= 0 || v > INT_MAX)
		return (false);

	out = static_cast<int>(v);
	return (true);
}

static void printFirstN(const std::vector<int> &v, size_t maxN)
{
	size_t n = v.size();
	size_t lim = (n < maxN) ? n : maxN;

	for (size_t i = 0; i < lim; i++)
	{
		std::cout << v[i];
		if (i + 1 < lim)
			std::cout << " ";
	}
	if (n > maxN)
		std::cout << " [...]";
}

void PmergeMe::printBefore(const std::vector<int> &v)
{
	std::cout << "Before: ";
	printFirstN(v, 20);
	std::cout << std::endl;
}

void PmergeMe::printAfter(const std::vector<int> &v)
{
	std::cout << "After:  ";
	printFirstN(v, 20);
	std::cout << std::endl;
}

double PmergeMe::elapsedUs(clock_t start, clock_t end)
{
	double seconds = static_cast<double>(end - start) / static_cast<double>(CLOCKS_PER_SEC);
	return (seconds * 1000000.0);
}

void PmergeMe::insertBoundedVector(std::vector<int> &mainChain, int value, int bound)
{
	std::vector<int>::iterator boundIt = std::find(mainChain.begin(), mainChain.end(), bound);
	if (boundIt == mainChain.end())
		boundIt = mainChain.end();
	std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), boundIt, value);
	mainChain.insert(pos, value);
}

void PmergeMe::insertBoundedDeque(std::deque<int> &mainChain, int value, int bound)
{
	std::deque<int>::iterator boundIt = std::find(mainChain.begin(), mainChain.end(), bound);
	if (boundIt == mainChain.end())
		boundIt = mainChain.end();
	std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), boundIt, value);
	mainChain.insert(pos, value);
}

static void buildPairsFromVector(const std::vector<int> &a,
	std::vector< std::pair<int,int> > &pairs, bool &hasOdd, int &odd)
{
	pairs.clear();
	hasOdd = false;
	odd = 0;

	size_t i = 0;
	while (i + 1 < a.size())
	{
		int x = a[i];
		int y = a[i + 1];
		if (x <= y)
			pairs.push_back(std::make_pair(x, y));
		else
			pairs.push_back(std::make_pair(y, x));
		i += 2;
	}
	if (i < a.size())
	{
		hasOdd = true;
		odd = a[i];
	}
}

static void buildPairsFromDeque(const std::deque<int> &a,
	std::vector< std::pair<int,int> > &pairs, bool &hasOdd, int &odd)
{
	pairs.clear();
	hasOdd = false;
	odd = 0;

	size_t i = 0;
	while (i + 1 < a.size())
	{
		int x = a[i];
		int y = a[i + 1];
		if (x <= y)
			pairs.push_back(std::make_pair(x, y));
		else
			pairs.push_back(std::make_pair(y, x));
		i += 2;
	}
	if (i < a.size())
	{
		hasOdd = true;
		odd = a[i];
	}
}

void PmergeMe::fordJohnsonVector(std::vector<int> &a)
{
	if (a.size() <= 1)
		return;
	std::vector< std::pair<int,int> > pairs;
	bool hasOdd;
	int odd;
	buildPairsFromVector(a, pairs, hasOdd, odd);
	std::vector<int> mainChain;
	mainChain.reserve(pairs.size() + (hasOdd ? 1 : 0));
	for (size_t i = 0; i < pairs.size(); i++)
		mainChain.push_back(pairs[i].second);
	if (hasOdd)
		mainChain.push_back(odd);
	fordJohnsonVector(mainChain);
	for (size_t i = 0; i < pairs.size(); i++)
		insertBoundedVector(mainChain, pairs[i].first, pairs[i].second);
	a.swap(mainChain);
}

void PmergeMe::fordJohnsonDeque(std::deque<int> &a)
{
	if (a.size() <= 1)
		return;
	std::vector< std::pair<int,int> > pairs;
	bool hasOdd;
	int odd;
	buildPairsFromDeque(a, pairs, hasOdd, odd);
	std::deque<int> mainChain;
	for (size_t i = 0; i < pairs.size(); i++)
		mainChain.push_back(pairs[i].second);
	if (hasOdd)
		mainChain.push_back(odd);
	fordJohnsonDeque(mainChain);
	for (size_t i = 0; i < pairs.size(); i++)
		insertBoundedDeque(mainChain, pairs[i].first, pairs[i].second);
	a.swap(mainChain);
}

void PmergeMe::run(int argc, char **argv)
{
	if (argc < 2)
		throw std::runtime_error("Error");

	_vec.clear();
	_deq.clear();

	for (int i = 1; i < argc; i++)
	{
		int v;
		if (!parseInt(argv[i], v))
			throw std::runtime_error("Error");
		_vec.push_back(v);
		_deq.push_back(v);
	}

	printBefore(_vec);

	clock_t startV = clock();
	fordJohnsonVector(_vec);
	clock_t endV = clock();

	clock_t startD = clock();
	fordJohnsonDeque(_deq);
	clock_t endD = clock();

	printAfter(_vec);

	double Vtime = elapsedUs(startV, endV);
	double Dtime = elapsedUs(startD, endD);

	std::cout << "Time to process a range of " << _vec.size()
		<< " elements with std::vector : " << Vtime << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size()
		<< " elements with std::deque  : " << Dtime << " us" << std::endl;
}
