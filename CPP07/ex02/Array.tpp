template <typename T>
Array<T>::Array() : arr(NULL), s(0) {}

template <typename T>
Array<T>::~Array() {
	delete[] arr;
}

template <typename T>
Array<T>::Array(unsigned int n) : s(static_cast<size_t>(n)) {
	arr = new T[n];
	for (size_t i = 0; i < n; i++){
		arr[i] = T();
	}
}

template <typename T>
Array<T>::Array(const Array &other) {
	*this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
	if (this == &other)
		return *this;
	s = other.size();
	if (s == 0) {
		arr = NULL;
		return *this;
	}
	arr = new T[s];
	for (size_t i = 0; i < s; ++i)
		arr[i] = other.arr[i];
	return *this;
}

template <typename T>
size_t Array<T>::size() const {
	return s;
}

template <typename T>
T& Array<T>::operator[](size_t i) {
	if (i >= s)
		throw std::runtime_error("Les capacites du tableau sont depassees");
	return arr[i];
}