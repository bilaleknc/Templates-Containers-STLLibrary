#include "Span.hpp"

Span::Span(void): _n(0)
{}

Span::Span(unsigned int n): _n(n)
{
	this->v.reserve(n);
}

Span::Span(Span const & src)
{
	*this = src;
}

Span::~Span(void)
{}

Span &	Span::operator=(Span const & rhs)
{
	this->_n = rhs._n;
	this->v = rhs.v;
	return *this;
}

void Span::addNumber(int n)
{
	try {
		if (this->v.size() < this->_n)
			this->v.push_back(n);
		else
			throw SpanFull();
	} catch (std::exception & e) {
		std::cerr << "Error: Span Full" << std::endl;
	}
}

void Span::randomAdd(){
	std::srand(std::time(0));
	for (unsigned int i = 0; i < this->_n; i++)
		addNumber(std::rand());
}

unsigned int Span::shortestSpan()
{
	if (this->v.size() < 2)
		throw SpanEmpty();
	std::vector<unsigned int> tmp = this->v;
	std::sort(tmp.begin(), tmp.end());
	size_t min = (size_t)tmp[1] - (size_t)tmp[0];
	for (size_t i = 0; i + 1 < _n ; i++){
		if ((size_t)tmp[i + 1] - (size_t)tmp[i] < min)
			min = (size_t)tmp[i + 1] - (size_t)tmp[i];
	}
	return min;
}

unsigned int Span::longestSpan()
{
	if (this->v.size() < 2)
		throw SpanEmpty();
	std::vector<unsigned int> tmp = this->v;
	std::sort(tmp.begin(), tmp.end());
	return (size_t)tmp[tmp.size() - 1] - (size_t)tmp[0];
}

const char *Span::SpanFull::what() const throw()
{
	return "Span is full!";
}
const char *Span::SpanEmpty::what() const throw()
{
	return "Not enough elements to calculate span!";
}