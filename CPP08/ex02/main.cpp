#include "MutantStack.hpp"
#include <list>

int main()
{
	std::cout << "--- Test de base ---\n";
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() <<  std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator it2 = mstack.end();
	std::cout << "Stack elements:\n";
	while (it != it2)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;
	std::cout << "--- Stack avec 1 élément ---" << std::endl;
	MutantStack<int> single;
	single.push(42);
	std::cout << "Top: " << single.top() << std::endl;
	for (MutantStack<int>::iterator it = single.begin(); it != single.end(); ++it)
		std::cout << "Iterating one element: " << *it << "\n" << std::endl;
	std::cout << "--- Stack de std::string ---\n";
	MutantStack<std::string> strStack;
	strStack.push("Bonjour");
	strStack.push("Monde\n");
	for (MutantStack<std::string>::iterator it = strStack.begin(); it != strStack.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << "--- Modification via itérateurs ---\n";
	MutantStack<int> mod;
	mod.push(1);
	mod.push(2);
	mod.push(3);
	for (MutantStack<int>::iterator it = mod.begin(); it != mod.end(); ++it)
		*it *= 10;
	for (MutantStack<int>::iterator it = mod.begin(); it != mod.end(); ++it)
		std::cout << *it << std::endl;
	return 0;
}

//int main()
//{
//	MutantStack<int> mstack;
//	mstack.push(5);
//	mstack.push(17);
//	std::cout << mstack.top() << std::endl;
//	mstack.pop();
//	std::cout << mstack.size() << std::endl;
//	mstack.push(3);
//	mstack.push(5);
//	mstack.push(737);
//	mstack.push(0);
//	MutantStack<int>::iterator it = mstack.begin();
//	MutantStack<int>::iterator ite = mstack.end();
//	++it;
//	--it;
//	while (it != ite)
//	{
//	std::cout << *it << std::endl;
//	++it;
//	}
//	std::stack<int> s(mstack);
//	std::cout << "-----" << std::endl;
//    std::list<int> lst;
//    lst.push_back(5);
//    lst.push_back(17);
//    std::cout << lst.back() << std::endl;
//    lst.pop_back();
//    std::cout << lst.size() << std::endl;
//    lst.push_back(3);
//    lst.push_back(5);
//    lst.push_back(737);
//    lst.push_back(0);
//    std::list<int>::iterator lit = lst.begin();
//    std::list<int>::iterator lite = lst.end();
//    while (lit != lite) {
//        std::cout << *lit << std::endl;
//        ++lit;
//    }
//    return 0;
//}

