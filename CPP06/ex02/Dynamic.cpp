#include "Dynamic.hpp"
#include <sys/time.h>

Base::~Base() {}

A::~A() {}

B::~B() {}

C::~C() {}

A::A() {}

B::B() {}

C::C() {}

long getTimee(){
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_usec;
}

Base *generate(void){
	std::srand(getTimee());
	int nb = std::rand() % 3;
	if (nb == 0){
		std::cout << "Objet de la classe A instancie" << std::endl;
		return new A;
	}
	else if (nb == 1){
		std::cout << "Objet de la classe B instancie" << std::endl;
		return new B;
	}
	else{
		std::cout << "Objet de la classe C instancie" << std::endl;
		return new C;
	}
}

void identify(Base *p){
	A *a = dynamic_cast<A*>(p);
	if (a != nullptr){
		std::cout << "Objet de type A identifie par fonction 1" << std::endl;
		return ;
	}
	B *b = dynamic_cast<B*>(p);
	if (b != nullptr){
		std::cout << "Objet de type B identifie par fonction 1" << std::endl;
		return ;
	}
	C *c = dynamic_cast<C*>(p);
	if (c != nullptr){
		std::cout << "Objet de type C identifie par fonction 1" << std::endl;
		return ;
	}
}

void identify(Base &p){
	try{
		A a = dynamic_cast<A&>(p);
		std::cout << "Objet de type A identifie par fonction 2\n";
		(void)a;
		return ;
	}
	catch (std::exception &e){
	}
	try{
		B b = dynamic_cast<B&>(p);
		std::cout << "Objet de type B identifie par fonction 2\n";
		(void)b;
		return ;
	}
	catch (std::exception &e){
	}
	try{
		C c = dynamic_cast<C&>(p);
		std::cout << "Objet de type C identifie par fonction 2\n";
		(void)c;
		return ;
	}
	catch (std::exception &e){
	}
	return ;
}
