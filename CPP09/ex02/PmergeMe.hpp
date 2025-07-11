#ifndef __PMERGEME_HPP__
# define __PMERGEME_HPP__

# include <iostream>
# include <string>
# include <vector>
# include <queue>

class Pmerge{
	private :
		std::vector<int> vec;
		std::deque<int>  qu;
		int *tab;
	public :
		Pmerge(const char **av);
		~Pmerge();
		Pmerge &operator=(const Pmerge &other);
		Pmerge(const Pmerge &other);
};

#endif
