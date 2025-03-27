#include "Serialize.hpp"

int main(){
	Data *data = new Data;
	uintptr_t t = Serializer::serialize(data);
	std::cout << "serialize: " << std::hex << t << std::endl;
	data = Serializer::deserialize(t);
	std::cout << "deserialize: " << data << std::endl;
	delete data;
	return 0;
}
