#include "PmergeMe.hpp"

std::vector<int> getJacobsthal(int n)
{
    std::vector<int> J;
	if (n <= 0)
		return J;
	J.push_back(0);
	if (n == 1)
		return J;
	J.push_back(1);
	if (n == 2)
		return J;
	while (1){
		long res = J[J.size() - 1] + 2 * J[J.size() - 2];
		if (res >= n)
			break ;
		if (res > INT_MAX)
			throw (std::runtime_error ("list to long for Jacobsthal order's implementation"));
		J.push_back(res);
	}
	return J;
}

std::vector<int> getIndices(int k)
{
    std::vector<int> out;
	if (k <= 0)	
		return out;
	std::vector<int> J = getJacobsthal(k);
	int last = 0;
	for (size_t idx = 1; idx < J.size(); idx++){
		int start = J[idx];
		int end = J[idx - 1];
		for (int i = start; i > end; i--){
			if (i < k){
				out.push_back(i);
			}
		}
		last = J[idx];
	}
	for (int i = last; i < k; i++)
		out.push_back(i);
    return out;
}

long getMsTime(){
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000 + tv.tv_usec / 1000;
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
	std::vector<int> indices = getIndices((int)smalls.size());
	for(std::vector<int>::iterator it = indices.begin(); it != indices.end(); it++)
		insertValue(bigs, smalls[*it]);
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
	std::vector<int> indices = getIndices((int)smalls.size());
	for(std::vector<int>::iterator it = indices.begin(); it != indices.end(); it++)
		insertValueBis(bigs, smalls[*it]);
	return bigs;
}

Pmerge::Pmerge(const char **av, bool arg2){
	int count = 0;
	if (arg2) {
		const char *s = av[0];
		int i = 0;
		while (s[i]) {
			while (s[i] && isspace(s[i]))
				i++;
			if (!s[i])
				break;
			int start = i;
			while (s[i] && !isspace(s[i]))
				i++;
			int len = i - start;
			std::string token(s + start, len);
			checkMax(token.c_str());
			int value = atoi(token.c_str());
			this->vec.push_back(value);
			this->dq.push_back(value);
		}
	}
	else{
		while (av[count]){
			checkMax(av[count]);
			this->vec.push_back(atoi(av[count]));
			this->dq.push_back(atoi(av[count]));
			count++;
		}
	}
	if (this->vec.empty())
		throw (std::runtime_error ("No value entered"));
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
	// for(std::vector<int>::iterator it = this->vec.begin(); it != this->vec.end(); it++){
	// 	std::cout << *it << " ";
	// }
	for(std::deque<int>::iterator it = this->dq.begin(); it != this->dq.end(); it++){
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
