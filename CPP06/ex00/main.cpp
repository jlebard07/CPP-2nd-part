#include "ScalarConvertor.hpp"

int main(int ac, char **av){
	std::string input;
	
	if (ac != 2)
		return (std::cout << "Please enter ONE arg" << std::endl), 1;
	input = av[1];
	ScalairConvertor::convert(input);
	return 0;
}
