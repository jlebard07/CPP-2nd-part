#ifndef __ITER__
# define __ITER__

# include <string>
# include <iostream>

template <typename T>

void display(T t){
	std::cout << t;
}

template <typename T>

void iter(T *array, size_t n, void(*f)(T)){
	for (size_t i = 0; i < n; i++){
		f(array[i]);
	}
	std::cout << "\n";
}

#endif
