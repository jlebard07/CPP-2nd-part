#include "BitcoinExchange.hpp"

bool	checkInput(char *str, const char *ext){
	size_t n = strlen(str);
	size_t m = strlen(ext);

	if (m >= n)
		return false;
	return (strcmp(str + n - m, ext)) == 0;
}

int main(int argc, char **argv){
	if (argc != 2){
		std::cerr << "Please insert only one argument to the programm" << std::endl;
		return 0;
	}
	if (checkInput(argv[1], ".txt") == 0){
				std::cerr << "Programm arguments is meant to be an existing .txt file" << std::endl;
					return 0;
			}
	try {
		BitcoinPrice btc(argv[1],  "data.csv");
	}	
	catch (std::runtime_error &e){
		std::cerr << e.what() << std::endl;
		return 0;
	}
	return 1;
}
