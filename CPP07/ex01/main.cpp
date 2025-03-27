#include "iter.hpp"

int main()
{
	char str[] = "bonjour";
	::iter(str, 8, &::display);
	int	arr[] = {1, 2, 3, 4};
	::iter(arr, 4, &display);
	double arrd[] = {121.34, 42.42, -4324.54};
	::iter(arrd, 3, &display);
}
