#include "Array.hpp"

template <typename T>
void display(T t){
	std::cout << t << std::endl;
}

int main()
{
	Array<int> A;
	Array<int> B(10);
	Array<int> C = B;
	Array<char> D(10);
	try{
		display(B[2]);
	}
	catch (std::runtime_error &e){
		std::cout << e.what() << std::endl;
	}
	B[2] = 4;
	try{
		display(C[2]);
	}
	catch (std::runtime_error &e){
		std::cout << e.what() << std::endl;
	}
}
