#include "BitcoinExchange.hpp"

void checkCsvLine(std::string line){
	for (int i = 0; i < 4; i++){
		if (line.c_str()[i] < 48 || line.c_str()[i] > 57){
			throw std::runtime_error("Bad format in csv file");
			std::cout << "1\n";
		}
		}
		if (line.c_str()[4] != '-' || line.c_str()[7] != '-' || line.c_str()[10] != ','){
			std::cout << "2\n";
			throw std::runtime_error("Bad format in csv file");
		}
		for (int i = 5; i < 7; i++){
			if (line.c_str()[i] < 48 && line.c_str()[i] > 57){
				std::cout << "3\n";
				throw std::runtime_error("Bad format in csv file");	
			}
		}
		for (int i = 8; i < 10; i++){
			if (line.c_str()[i] < 48 && line.c_str()[i] > 57){
				std::cout << "4\n";
				throw std::runtime_error("Bad format in csv file");	
			}
		}
		int count = 0;
		for (int i = 11; line.c_str()[i]; i++){
			if (isdigit(line.c_str()[i] == 0)){
				if (line.c_str()[i] == '.' && count < 1)
				count++;
			else{
				std::cout << "5\n";
				throw std::runtime_error("Bad format in csv file");
			}
		}
	}
}

void checkTxtFile(std::string line){
	for (int i = 0; i < 4; i++){
		if (line.c_str()[i] < 48 || line.c_str()[i] > 57)
			throw std::runtime_error("Bad format in txt file1");
		}
	if (line.c_str()[4] != '-' || line.c_str()[7] != '-' || line.c_str()[10] != ' ' || line.c_str()[11] != '|' || line.c_str()[12] != ' ')
		throw std::runtime_error("Bad format in txt file2");
	for (int i = 5; i < 7; i++){
		if (line.c_str()[i] < 48 && line.c_str()[i] > 57)
			throw std::runtime_error("Bad format in txt file3");
	}
	for (int i = 8; i < 10; i++){
		if (line.c_str()[i] < 48 && line.c_str()[i] > 57)
			throw std::runtime_error("Bad format in txt file4");	
	}
	int count = 0;
	for (int i = 13; line.c_str()[i]; i++){
		if (isdigit(line.c_str()[i] == 0)){
			if (line.c_str()[i] == '.' && count < 1)
				count++;
			else
				throw std::runtime_error("Bad format in txt file5");
		}
	}
}

Date fillDate(const char *line){
	Date dest;
	dest.year = atoi(line);
	dest.mounth = atoi (line + 5);
	dest.day = atoi (line + 8);
	return dest;
}

void checkDate(Date &d){
	if (d.mounth > 12 || d.mounth < 1)
		throw std::runtime_error("Bad date format identified");
	if (d.day > 31)
		throw std::runtime_error("Bad date format identified");
	if ((d.mounth == 2 || d.mounth == 4 || d.mounth == 6 || d.mounth == 9 || d.mounth == 11) && d.day > 30)
		throw std::runtime_error("Bad date format identified");
	if (d.mounth == 2 && d.day > 29)
		throw std::runtime_error("Bad date format identified");
	if (d.mounth == 2 && d.year % 4 != 0 && d.day > 28)
		throw std::runtime_error("Bad date format identified");
}

BitcoinPrice::BitcoinPrice(char *file1, char *file2) : _data_file(file1), _input_file(file2){
	if (_data_file.good() == 0 || _input_file.good() == 0)
		throw std::runtime_error("Error opening file");
	std::string line;
	int i = 0;
	while (getline(_data_file, line)){
		if (i != 0){
			checkCsvLine(line);
			Date d = fillDate(line.c_str());
			checkDate(d);
			if (!_data.empty())
				checkForSameDate(d, 0);
			_data[d] = atof (line.c_str() + 10);
			if (_data[d] < 0)
				throw std::runtime_error("Bitcoin value cant be lower than 0");
			}
			else if (i == 0 && strcmp(line.c_str(), "date,exchange_rate") != 0){
				throw std::runtime_error("Bad header in csv file");
			}
			i++;
		}
		i = 0;
		while (getline(_input_file, line)){
			if (i != 0){
				checkTxtFile(line);
				Date d = fillDate(line.c_str());
				checkDate(d);
				if (!_input.empty())
					checkForSameDate(d, 1);
				_input[d] = atof (line.c_str() + 12);
				if (_input[d] <= 0 || _input[d] > 1000){
					std::cout << _input[d] << std::endl;
					throw std::runtime_error("Txt values have to be between 0 and 1000");
				}
		}
		else if (i == 0 && strcmp(line.c_str(), "date | value") != 0){
			throw std::runtime_error("Bad header in txt file");
		}
		i++;
	}
	for (std::map<Date, double>::iterator it = _input.begin(); it != _input.end(); it++){
		std::cout << it->first.year << it->first.mounth << it->first.day << " : " << it->second << std::endl;
	}
}

void BitcoinPrice::calculateRender(){
	for (std::map<Date, double>::iterator it = _input.begin(); it != _input.end(); it++){
		if ()
	}
}

BitcoinPrice::~BitcoinPrice() {
	calculateRender();
}

BitcoinPrice::BitcoinPrice(const BitcoinPrice &other){
	*this = other;
}

BitcoinPrice &BitcoinPrice::operator=(const BitcoinPrice &other){
	if (this == &other)
		return *this;
	this->_data = other._data;
	this->_input = other._input;
	return *this;
}
