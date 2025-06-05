#include "easyfind.hpp"

int main(){
	try {
		std::vector <int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);
		std::list <int> lst;
		lst.push_back(1);
		lst.push_back(2);
		lst.push_back(3);
		lst.push_back(4);
		lst.push_back(5);
		std::vector <int>::iterator itVec = easyfind(vec, 3);
		std::cout << "Found in vector: " << *itVec << std::endl;
		std::list <int>::iterator itLst = easyfind(lst, 6);
		std::cout << "Found in list: " << *itLst << std::endl;
		}
	catch (const std::runtime_error &e) {
		std::cerr << e.what() << std::endl;
	}
}
