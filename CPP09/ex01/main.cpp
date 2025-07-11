#include "RPN.hpp"

int main(int ac, char **av){
	if (ac != 2)
		return std::cout << "Pls enter one argument" << std::endl, 1;
	for (int i = 0; av[1][i]; i++){
		if (isdigit(av[1][i]) == 0 && av[1][i] != ' ' && av[1][i] != '+' && av[1][i] != '-' && av[1][i] != '*' && av[1][i] != '/')
			return std::cout << "Pls enter a valid RPN expression" << std::endl, 1;
	}
	try {
		RPN rpn(av[1]);
		std::cout << rpn.getResult() << std::endl;
	}
	catch (std::runtime_error &e){
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}
