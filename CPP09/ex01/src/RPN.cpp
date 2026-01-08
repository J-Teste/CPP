#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &other)
{
	(void)(other);
}

RPN &RPN::operator=(const RPN &other)
{
	(void)(other);
	return (*this);
}

RPN::~RPN()
{
}

bool RPN::isOp(const std::string &t)
{
	if (t.size() != 1)
		return (false);
	return (t[0] == '+' || t[0] == '-' || t[0] == '*' || t[0] == '/');
}

bool RPN::isDigit(const std::string &t)
{
	if (t.size() != 1)
		return (false);
	return (t[0] >= '0' && t[0] <= '9');
}

long RPN::doOp(long a, long b, char op)
{
	if (op == '+')
		return (a + b);
	if (op == '-')
		return (a - b);
	if (op == '*')
		return (a * b);
	if (b == 0)
		throw std::runtime_error("Error : Division by zero.");
	return (a / b);
}

long RPN::evaluate(const std::string &input)
{
	std::stack<long>	s;
	std::istringstream	iss(input);
	std::string			token;

	while (iss >> token)
	{
		if (isDigit(token))
			s.push(static_cast<long>(token[0] - '0'));
		else if (isOp(token))
		{
			if (s.size() < 2)
				throw std::runtime_error("Error : Not enough operands.");
			long b = s.top();
			s.pop();
			long a = s.top();
			s.pop();

			long r = doOp(a, b, token[0]);
			s.push(r);
		}
		else
			throw std::runtime_error("Error : Invalid token.");
	}

	if (s.size() != 1)
		throw std::runtime_error("Error : Invalid expression.");
	return (s.top());
}
