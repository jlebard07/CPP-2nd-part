#ifndef __SERIALIZE__
# define __SERIALIZE__

# include <iostream>
# include <string>
#include <stdint.h>

typedef struct sData{
	int n;
}Data;

class Serializer{
	private :
		Serializer();
		~Serializer();
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);
	public :
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);		
};

#endif
