#include "ScalarConvertor.hpp"
#include <iomanip>

ScalairConvertor::ScalairConvertor() {}

ScalairConvertor::~ScalairConvertor() {}

ScalairConvertor &ScalairConvertor::operator=(ScalairConvertor &other){
	if (this == &other)
		return *this;
	return *this;	
}

ScalairConvertor::ScalairConvertor(ScalairConvertor &other) {
	*this = other;
}

static void impossible(){
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

static void	displayChar(float f){
	char c = 0;
	if (f <= 255.0 && f >= 0.0){
		c = static_cast<char>(f);
		if (std::iscntrl(c))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << c << "'" << std::endl;
	}
	else{
		std::cout << "char: impossible" << std::endl;
	}
}

static void	displayNan(){
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

static void displayMinf(){
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: -inff" << std::endl;
	std::cout << "double: -inf" << std::endl;
}

static void displayPinf(){
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: +inff" << std::endl;
	std::cout << "double: +inf" << std::endl;
}

static int countPoints(std::string str){
	int i = 0;
	int count = 0;

	while (str[i++]){
		if (str[i] == '.')
			count++;
	}
	return (count);
}

void dealChar(std::string str){
	char c = str[0];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);
	displayChar(f);
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
}

void ScalairConvertor::convert(std::string str){
	float f;
	unsigned long n;
	n = str.size();
	if (str == "nan")
		return displayNan();
	else if (str == "-inf")
		return displayMinf();
	else if (str == "+inf")
		return displayPinf();
	for (unsigned long i = 1; i < n - 1; i++){
		if (std::isdigit(str[i]) == 0 && str[i] != '.')
			return impossible();
	}
	if (n != 1 && str[n - 1] != 'f' && std::isdigit(str[n - 1]) == 0)
		return impossible();
	if (countPoints(str) > 1)
		return impossible();
	f = std::atof(str.c_str());
	if (f != 0){
		int i = static_cast<int>(f);
		double d = static_cast<double>(f);
		displayChar(f);
		if (f <= 2147483647.0 && f >= -2147482648.0)
			std::cout << "int: " << i << std::endl;
		else
			std::cout << "int: risk of overflow" << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
	}
	else
		dealChar(str);
}
