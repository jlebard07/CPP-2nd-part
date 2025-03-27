#include "Dynamic.hpp"

void identify(Base *p);

void identify(Base &p);

Base *generate(void);

int main(){
	Base *p = generate();
	identify (p);
	identify (*p);
	delete p;
}
