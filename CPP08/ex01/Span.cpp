#include "Span.hpp"
#include <limits.h>

Span::Span(unsigned int n) : _N(n) {}

Span::~Span() {}

Span::Span(const Span &other){
	*this = other;
}

Span &Span::operator=(const Span &other){
	if (this == &other)
		return *this;
	this->_N = other._N;
	this->_vec = other._vec;
	return *this;
}

void Span::addNumber(int n){
	if (this->_vec.size() > _N - 1)
		throw (std::runtime_error("Size_max of std::vector is reached"));
	this->_vec.push_back(n);
}

int Span::longestSpan(){
	int min = INT_MAX;
	int max = INT_MIN;
	
	if (this->_vec.size() < 2)
		throw (std::runtime_error("Size of std::vector is too little to get a span"));
	for (std::vector <int>::iterator it = this->_vec.begin(); it != this->_vec.end(); it ++){
		if (*it < min)
			min = *it;
		if (*it > max)
			max = *it;
	}
	return max - min;
}

int Span::shortestSpan(){
	int shortS = INT_MAX;

	if (this->_vec.size() < 2)
		throw (std::runtime_error("Size of std::vector is too little to get a span"));
	for (std::vector <int>::iterator it = this->_vec.begin(); it != this->_vec.end(); it ++){
		for (std::vector <int>::iterator it2 = this->_vec.begin(); it2 != this->_vec.end(); it2 ++){
			if (it != it2){
				if (*it2 >= *it && *it2 - *it < shortS)
					shortS = *it2 - *it;
				else if (*it >= *it2 &&  *it - *it2 < shortS)
					shortS = *it - *it2;
			}
		}
	}
	return shortS;
}

void Span::addSeveral(std::vector <int>::iterator it, std::vector <int>::iterator it2){
	for (std::vector <int>::iterator it3 = it; it3 != it2; it3++){
		this->addNumber(*it3);
	}
}

void Span::displayVec(){
	for (std::vector<int>::iterator it = this->_vec.begin(); it != this->_vec.end(); it++){
		std::cout << *it << "\n";
	}
}

