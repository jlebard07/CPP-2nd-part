#ifndef __ARRAY__
# define __ARRAY__

# include <iostream>
# include <string>
# include "Array.tpp"

template <typename T>
class Array{
	private :
		T *arr;
	public :
		Array();
		~Array();
		Array(int n);
		Array(const Array &other);
		Array &operator=(const Array &other);
		size_t size() const;
};

#endif
