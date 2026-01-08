#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <iostream>


class RPN
{
	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		static long	evaluate(const std::string &expr);

	private:
		static bool	isOp(const std::string &t);
		static bool	isDigit(const std::string &t);
		static long	doOp(long a, long b, char op);
};

#endif
