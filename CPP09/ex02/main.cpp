#include "PmergeMe.hpp"

bool check_input(char **av, bool arg2){
	if (!arg2){
		for (int i = 0; av[i]; i++){
			for (int j = 0; av[i][j]; j++){
				if (!isdigit(av[i][j]))
					return 0;
			}
		}
	}
	else{
		for (int i = 0; av[0][i]; i++)
			if (!isdigit(av[0][i]) && !isspace(av[0][i]))
				return 0;
	}
	return 1;
}

int main(int ac, char **av){
	if (ac < 2){
		std::cerr << "Please insert 2 args or more" << std::endl;
		return 1;
	}
	if (!check_input(av + 1, ac == 2)){
		std::cerr << "Error" << std::endl;
		return 1;
	}
	try {
		Pmerge bonjour((const char **)av + 1, ac == 2);
	}
	catch (std::runtime_error &e){
		std::cout << e.what() << std::endl;
		return 1;
	}
}
