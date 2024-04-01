#ifndef SPAN_HPP
#	define SPAN_HPP

#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

class Span {
	private:
		unsigned int _n;
		std::vector<unsigned int> v;

	public:
		Span();
		Span(unsigned int n);
		Span(Span const & src);
		~Span(void);
		Span & operator=(Span const & rhs);
		void addNumber(int n);
		void randomAdd();
		unsigned int shortestSpan();
		unsigned int longestSpan();

		class SpanFull : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};

		class SpanEmpty : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};
};

#endif