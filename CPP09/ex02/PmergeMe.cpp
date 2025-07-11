#include "PmergeMe.hpp"

std::vector<int> sortVec(std::vector<int> &vec){
	if (vec.size() < 2)
		return ;
	
	std::vector<int> bigs;
	std::vector<int> smalls;
	for (int i = 0; vec[i]; i++){
		if (vec[i + 1] and i % 2 == 0){
			if (vec[i] > vec[i + 1]){
				bigs.push_back(vec[i]);
				smalls.push_back(vec[i + 1]);
			}
			else{
				bigs.push_back(vec[i + 1]);
				smalls.push_back(vec[i]);
			}
		}
		if (vec.size() % 2 == 1)
			smalls.push_back(vec.back());
	}
}

Pmerge::Pmerge(const char **av){
	int count = 0;
	while (av[count])
		count++;
	this->tab = new int[count];
	for (int i = 0; av[i]; i++){
		tab[i] = atoi(av[i]);
	}
	int i = 0;
	while (tab[i])
		this->vec.push_back(tab[i++]);
	this->vec = sortVec(this->vec);
}

Pmerge::~Pmerge(){
	delete this->tab;
}

Pmerge &Pmerge::operator=(const Pmerge &other){
	if (this == &other)
		return *this;
	this->qu = other.qu;
	this->vec = other.vec;
	return *this;
}

Pmerge::Pmerge(const Pmerge &other){
	*this = other;
}
