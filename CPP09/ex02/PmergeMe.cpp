#include "PmergeMe.hpp"

long getMsTime(){
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000000 + tv.tv_usec;
}

void checkMax(const char *str){
	long l;
	l = atol(str);
	if (strlen(str) > 10 || l > INT_MAX)
		throw (std::runtime_error ("Please enter values < INT_MAX"));
}

void insertValue(std::vector<int> &vec, int n){
	if (vec.size() == 1){
		vec.insert(vec.begin(), n);
		return ;
	}
	int left = 0;
	int right = (int)vec.size();
	while (left < right){
		int mid = (left + right) / 2;
		if (vec[mid] < n)
			left = mid + 1;
		else
			right = mid;
	}
	vec.insert(vec.begin() + left, n);
}

std::vector<int> sortVec(std::vector<int> &vec){
	if (vec.size() < 2)
		return vec;
	
	std::vector<int> bigs;
	std::vector<int> smalls;
	for (int i = 0; i + 1 < (int)vec.size(); i += 2){
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
	bigs = sortVec(bigs);
	for (std::vector<int>::iterator it = smalls.begin(); it != smalls.end(); it++)
		insertValue(bigs, *it);
	return bigs;
}

void insertValueBis(std::deque<int> &dq, int n){
	if (dq.size() == 1){
		dq.insert(dq.begin(), n);
		return ;
	}
	int left = 0;
	int right = (int)dq.size();
	while (left < right){
		int mid = (left + right) / 2;
		if (dq[mid] < n)
			left = mid + 1;
		else
			right = mid;
	}
	dq.insert(dq.begin() + left, n);
}

std::deque<int> sortDq(std::deque<int> &dq){
	if (dq.size() < 2)
		return dq;
	std::deque<int> bigs;
	std::deque<int> smalls;
	for (int i = 0; i + 1 < (int)dq.size(); i += 2){
		if (dq[i] > dq[i + 1]){
			bigs.push_back(dq[i]);
			smalls.push_back(dq[i + 1]);
		}
		else{
			smalls.push_back(dq[i]);
			bigs.push_back(dq[i + 1]);
		}
	}
	if (dq.size() % 2 == 1)
		smalls.push_back(dq.back());
	bigs = sortDq(bigs);
	for(int i = 0; i < (int)smalls.size(); i++)
		insertValueBis(bigs, smalls[i]);
	return bigs;
}

Pmerge::Pmerge(const char **av){
	int count = 0;
	while (av[count]){
		checkMax(av[count]);
		this->vec.push_back(atoi(av[count]));
		this->dq.push_back(atoi(av[count]));
		count++;
	}
	std::cout << "Before :\t";
	for (std::vector<int>::iterator it = this->vec.begin(); it != this->vec.end(); it++){
		std::cout << *it << " ";
	}
	std::cout << '\n';
	long start = getMsTime();
	this->vec = sortVec(this->vec);
	long end = getMsTime();
	dVec = end - start;
	start = getMsTime();
	this->dq = sortDq(this->dq);
	end = getMsTime();
	this->dDq = end - start;
}

Pmerge::~Pmerge(){
	std::cout << "After :\t\t";
	for(std::vector<int>::iterator it = this->vec.begin(); it != this->vec.end(); it++){
		std::cout << *it << " ";
	}
	std::cout << "\n";
	std::cout << "Time to process a range of " << this->vec.size() << " elements with std::vector : " << this->dVec << " ms" << std::endl;
	std::cout << "Time to process a range of " << this->vec.size() << " elements with std::deque : " << this->dDq << " ms" << std::endl;
}

Pmerge &Pmerge::operator=(const Pmerge &other){
	if (this == &other)
		return *this;
	this->dq = other.dq;
	this->vec = other.vec;
	return *this;
}

Pmerge::Pmerge(const Pmerge &other){
	*this = other;
}
