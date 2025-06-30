#ifndef __BITCOIN_EXCHANGE__
# define __BITCOIN_EXCHANGE__

# include <iostream>
# include <string>
# include <map>
# include <algorithm>
# include <fstream>
# include <cstring>

struct Date{
	int year, mounth, day;
	std::string fullDate;
	
bool operator<(const Date &other) const {
	if (year != other.year) return year < other.year;
	if (mounth != other.mounth) return mounth < other.mounth;
	return day < other.day;
}
	bool operator==(const Date&other) const {
		if (year == other.year && mounth == other.mounth && day == other.day)
			return true;
		return false;
	}
};

class BitcoinPrice{
	private :
		std::map <Date, double> _data;
		std::ifstream _data_file;
		std::ifstream _input_file;
	public :
		BitcoinPrice(const char *file1, const char *file2);
		~BitcoinPrice();
		BitcoinPrice(const BitcoinPrice &other);
		BitcoinPrice &operator=(const BitcoinPrice &other);
};

#endif
