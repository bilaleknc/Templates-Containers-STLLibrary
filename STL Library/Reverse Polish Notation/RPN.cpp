#include "RPN.hpp"
#include <iostream>
#include <cstdlib>

RPNCalculator::RPNCalculator()
{}

RPNCalculator::RPNCalculator(const RPNCalculator &other)
{
	*this = other;
}

RPNCalculator::~RPNCalculator()
{}

RPNCalculator &RPNCalculator::operator=(const RPNCalculator &other)
{
	(void)other;
	return *this;
}


void RPNCalculator::check_error(const std::string &s)
{
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
			continue;
		std::string validChars = "0123456789+-*/";
		if (validChars.find(s[i]) == std::string::npos)
		{
			std::cerr << "Error: invalid character" << std::endl;
			exit(1);
		}
	}
}

int RPNCalculator::evaluate(const std::string &s)
{
	std::stack<int> stack;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
			continue;
		if (s[i] >= '0' && s[i] <= '9')
			stack.push(s[i] - '0');
		else
		{
			int a = stack.top();
			stack.pop();
			int b = stack.top();
			stack.pop();
			switch (s[i])
			{
			case '+':
				stack.push(a + b);
				break;
			case '-':
				stack.push(b - a);
				break;
			case '*':
				stack.push(a * b);
				break;
			case '/':
				stack.push(b / a);
				break;
			}
		}
	}
	if (stack.size() > 1)
	{
		std::cerr << "Error: invalid expression" << std::endl;
		exit(1);
	}
	return stack.top();
}
