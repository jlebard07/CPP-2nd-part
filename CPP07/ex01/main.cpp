#include "iter.hpp"
#include <iostream>

class A{
	private : 
	public :
};

std::ostream &operator<<(std::ostream &os, const A &a){
	os << "a\n";
	(void)a;
	return os;
}

int main()
{
	char str[] = "bonjour";
	iter(str, 8, &::display);
	int	arr[] = {1, 2, 3, 4};
	iter(arr, 4, &display);
	double arrd[] = {121.34, 42.42, -4324.54};
	iter(arrd, 3, &display);
	A *a = new A[3];
	iter(a, 3, &display);
}
