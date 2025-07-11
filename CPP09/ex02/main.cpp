#include "PmergeMe.hpp"

bool check_input(char **av){
	for (int i = 0; av[i]; i++){
		for (int j = 0; av[i][j]; j++){
			if (!isdigit(av[i][j]))
				return 0;
		}
	}
	return 1;
}

int main(int ac, char **av){
	if (ac < 3){
		std::cerr << "Please insert 2 args or more" << std::endl;
		return 1;
	}
	if (check_input(av) == 0){
		std::cerr << "Error" << std::endl;
		return 1;
	}
	Pmerge bonjour((const char **)av);
}
