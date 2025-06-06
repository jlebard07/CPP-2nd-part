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
	
	bool operator<(const Date &other) const {
		if (year < other.year) return true;
		if (mounth < other.mounth) return true;
		if (day < other.day) return true;
		return 0; 
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
		std::map <Date, double> _input;
		std::ifstream _data_file;
		std::ifstream _input_file;
	public :
		BitcoinPrice(char *file1, char *file2);
		~BitcoinPrice();
		BitcoinPrice(const BitcoinPrice &other);
		BitcoinPrice &operator=(const BitcoinPrice &other);
		void checkForSameDate(Date &d, bool txt);
		void calculateRender();
};

#endif
