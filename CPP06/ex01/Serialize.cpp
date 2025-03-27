#include "Serialize.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer &Serializer::operator=(const Serializer &other){
	if (this == &other)
		return *this;
	return *this;
}

Serializer::Serializer(const Serializer &other){
	*this = other;
}

uintptr_t Serializer::serialize(Data *ptr){
	uintptr_t dest = reinterpret_cast<uintptr_t>(ptr);
	return dest;
}

Data *Serializer::deserialize(uintptr_t raw){
	Data *data = reinterpret_cast<Data *>(raw);
	return data;
}
