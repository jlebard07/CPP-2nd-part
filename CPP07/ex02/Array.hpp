#ifndef __ARRAY__
# define __ARRAY__

# include <iostream>
# include <string>
# include <stdexcept>

template <typename T>
class Array {
	private:
		T* arr;
		size_t s;
	public:
		Array();
		~Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		size_t size() const;
		T& operator[](size_t i);
};

# include "Array.tpp"

#endif