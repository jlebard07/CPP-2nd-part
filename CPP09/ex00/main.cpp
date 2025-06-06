#include "BitcoinExchange.hpp"

bool	checkInput(char *str, const char *ext){
	size_t n = strlen(str);
	size_t m = strlen(ext);

	if (m >= n)
		return false;
	return (strcmp(str + n - m, ext)) == 0;
}

int main(int argc, char **argv){
	if (argc != 3){
		std::cerr << "Please insert two arguments to the programm" << std::endl;
		return 0;
	}
	if (checkInput(argv[1], ".csv") == 0 || checkInput(argv[2], ".txt") == 0) {
				std::cerr << "Programm arguments are meant to be one csv file and one txt file in that order" << std::endl;
					return 0;
			}
	try {
		BitcoinPrice btc(argv[1], argv[2]);
	}	
	catch (std::runtime_error &e){
		std::cerr << e.what() << std::endl;
		return 0;
	}
	return 1;
}
