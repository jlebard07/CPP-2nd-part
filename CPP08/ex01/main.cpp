#include "Span.hpp"

int main(){
	Span r(5);
	try{
		r.addNumber(1);
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		r.shortestSpan();
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		r.addNumber(1000);
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		r.addNumber(2);
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		r.addNumber(87);
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		r.addNumber(101);
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		r.addNumber(0);
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "Shortest span : " << r.shortestSpan() << std::endl;
	std::cout << "Longest span : " << r.longestSpan() << std::endl;

	Span S(7);
	std::vector <int> vec;
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	try{
		S.addSeveral(vec.begin(), vec.end());
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	S.displayVec();
}
