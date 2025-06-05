#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>

template <typename T>
typename T::iterator easyfind(T &container, int value) {
	for (typename T::iterator it = container.begin(); it != container.end(); it++){
		if (*it == value)
			return it;
	}
	std::ostringstream oss;
	oss << "Value " << value << " not found in container.";
	throw std::runtime_error(oss.str());
}

#endif
