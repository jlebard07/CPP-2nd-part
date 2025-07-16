#include "Array.hpp"

template <typename T>
Array<T>::Array() : s(0){
}

template <typename T>
Array<T>::~Array() {}

template <typename T>
Array<T>::Array(unsigned int n) : s(static_cast<size_t>(n)){
	this->arr = new T[n];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other){
	if (this == &other)
		return *this;
	delete []this->arr;
	if (other.size() == 0){
		this->s = 0;
		return *this;
	}
	this->arr = new T[other.size()];
	for (int i = 0; i < other.size(); i++)
		this->arr[i] = other.arr[i];
	this->s = other.size();
	return *this;
}

template <typename T>
Array<T>::Array(const Array &other){
	*this = other;
}

template <typename T>
size_t Array<T>::size() const {
	return this->s;
}

template <typename T>
T &Array<T>::operator[](size_t i){
	if (i >= this->s)
		throw (std::runtime_error("Les capacites du tableau sont depassees"));
	return this->arr[i];
}
