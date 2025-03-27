#include "Array.hpp"

template <typename T>
Array<T>::Array() {}

template <typename T>
Array<T>::~Array() {}

template <typename T>
Array<T>::Array (int n){
	this->arr = new T[n];
}

template <typename T>
size_t Array<T>::size() const{
	size_t i = 0;

	while (this->arr[i])
		i++;
	return i;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other){
	if (this = &other)
	return *this;
	this->arr = new arr[other.size()];
	return *this;
}

template <typename T>
Array<T>::Array(const Array *other){
	*this = other;
}
