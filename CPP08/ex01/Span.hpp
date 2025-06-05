#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span {
	private :
		unsigned int _N;
		std::vector <int> _vec;
	public :
		Span(unsigned int n);
		~Span();
		Span(const Span &other);
		Span &operator=(const Span &other);
		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
		void addSeveral(std::vector <int>::iterator it, std::vector <int>::iterator it2);
};

#endif
