#include "BitcoinExchange.hpp"

void checkCsvLine(std::string line){
	for (int i = 0; i < 4; i++){
		if (line.c_str()[i] < 48 || line.c_str()[i] > 57)
			throw std::runtime_error("Bad input : " + line);
		}
	if (line.c_str()[4] != '-' || line.c_str()[7] != '-' || line.c_str()[10] != ',')
			throw std::runtime_error("Bad input : " + line);
	for (int i = 5; i < 7; i++){
		if (line.c_str()[i] < 48 && line.c_str()[i] > 57)
			throw std::runtime_error("Bad input : " + line);	
		}
	for (int i = 8; i < 10; i++){
		if (line.c_str()[i] < 48 && line.c_str()[i] > 57)
			throw std::runtime_error("Bad input : " + line);	
	}
	int count = 0;
	for (int i = 11; line.c_str()[i]; i++){
		if (isdigit(line.c_str()[i] == 0)){
			if (line.c_str()[i] == '.' && count < 1)
				count++;
			else
				throw std::runtime_error("Bad input : " + line);
		}
	}
}

bool checkTxtFile(std::string line){
	for (int i = 0; i < 4; i++){
		if (line.c_str()[i] < 48 || line.c_str()[i] > 57)
			return std::cout << "Bad input : " << line << std::endl, 0;
		}
	if (line.c_str()[4] != '-' || line.c_str()[7] != '-' || line.c_str()[10] != ' ' || line.c_str()[11] != '|' || line.c_str()[12] != ' ')
		return std::cout << "Bad input : " << line << std::endl, 0;
	for (int i = 5; i < 7; i++){
		if (line.c_str()[i] < 48 && line.c_str()[i] > 57)
			return std::cout << "Bad input : " << line << std::endl, 0;
	}
	for (int i = 8; i < 10; i++){
		if (line.c_str()[i] < 48 && line.c_str()[i] > 57)
			return std::cout << "Bad input : " << line << std::endl, 0;
	}
	int count = 0;
	for (int i = 13; line.c_str()[i]; i++){
		if (isdigit(line.c_str()[i] == 0)){
			if (line.c_str()[i] == '.' && count < 1)
				count++;
			else
				return std::cout << "Bad input : " << line << std::endl, 0;
		}
	}
	return 1;
}

Date fillDate(const char *line){
	Date dest;
	dest.year = atoi(line);
	dest.mounth = atoi (line + 5);
	dest.day = atoi (line + 8);
	dest.fullDate = std::string(line, 10);
	return dest;
}

bool checkDateNotT(Date &d){
	if (d.mounth > 12 || d.mounth < 1)
		return std::cout << "Bad date format identified : " << d.fullDate << std::endl, 0;
	if (d.day > 31)
		return std::cout << "Bad date format identified : " << d.fullDate << std::endl, 0;
	if ((d.mounth == 2 || d.mounth == 4 || d.mounth == 6 || d.mounth == 9 || d.mounth == 11) && d.day > 30)
		return std::cout << "Bad date format identified : " << d.fullDate << std::endl, 0;
	if (d.mounth == 2 && d.day > 29)
		return std::cout << "Bad date format identified : " << d.fullDate << std::endl, 0;
	if (d.mounth == 2 && d.year % 4 != 0 && d.day > 28)
		return std::cout << "Bad date format identified : " << d.fullDate << std::endl, 0;
	return 1;
}

void checkDate(Date &d){
	if (d.mounth > 12 || d.mounth < 1)
		throw std::runtime_error("Bad date format identified => " + d.fullDate);
	if (d.day > 31)
		throw std::runtime_error("Bad date format identified => " + d.fullDate);
	if ((d.mounth == 2 || d.mounth == 4 || d.mounth == 6 || d.mounth == 9 || d.mounth == 11) && d.day > 30)
		throw std::runtime_error("Bad date format identified => " + d.fullDate);
	if (d.mounth == 2 && d.day > 29)
		throw std::runtime_error("Bad date format identified => " + d.fullDate);
	if (d.mounth == 2 && d.year % 4 != 0 && d.day > 28)
		throw std::runtime_error("Bad date format identified => " + d.fullDate);
}

void calculateRender(Date &d, double v, std::map<Date, double> &_data){	
	std::map<Date, double>::iterator closest = _data.end();
	for (std::map<Date, double>::iterator it2 = _data.begin(); it2 != _data.end(); it2++){
		if (it2->first == d){
			closest = it2;
			break;
		}
		else if (it2->first < d && (closest == _data.end() || closest->first < it2->first))
			closest = it2;
	}
	if (closest == _data.end()){
		throw std::runtime_error("No data found for date: " + d.fullDate);
	}
	std::cout << d.fullDate << " => " << v << " = " << closest->second * v << std::endl;
}

BitcoinPrice::BitcoinPrice(const char *file1, const char *file2) : _data_file(file2), _input_file(file1){
	if (_data_file.good() == 0 || _input_file.good() == 0)
		throw std::runtime_error("Error opening file");
	std::string line;
	int i = 0;
	while (getline(_data_file, line)){
		if (i != 0){
			checkCsvLine(line);
			Date d = fillDate(line.c_str());
			checkDate(d);
			size_t commaPos = line.find(',');
			if (commaPos == std::string::npos || commaPos + 1 >= line.size())
				throw std::runtime_error("Error parsing line: " + line);
			double value = atof(line.c_str() + commaPos + 1);
			if (value < 0)
				throw std::runtime_error("Error: not a positive number : " + line);
			_data[d] = value;
		}
		else if (i == 0 && strcmp(line.c_str(), "date,exchange_rate") != 0){
				throw std::runtime_error("Bad header in csv file");
		}
		i++;
	}
	i = 0;
	while (getline(_input_file, line)){
		if (i != 0){
			if (!checkTxtFile(line))
				continue;
			Date d = fillDate(line.c_str());
			if (!checkDateNotT(d))
				continue;
			double v = atof (line.c_str() + 12);
			if (v <= 0 || v > 1000){
				std::cout << "Error : too large number" << std::endl;
				continue;
			}
			calculateRender(d, v, this->_data);
		}
		else if (i == 0 && strcmp(line.c_str(), "date | value") != 0){
			throw std::runtime_error("Bad header in txt file");
		}
		i++;
	}
}

BitcoinPrice::~BitcoinPrice() {
	if (_data_file.is_open())  _data_file.close();
    if (_input_file.is_open()) _input_file.close();
}

BitcoinPrice::BitcoinPrice(const BitcoinPrice &other){
	*this = other;
}

BitcoinPrice &BitcoinPrice::operator=(const BitcoinPrice &other){
	if (this == &other)
		return *this;
	this->_data = other._data;
	return *this;
}
