#ifndef __PMERGEME_HPP__
# define __PMERGEME_HPP__

# include <iostream>
# include <string>
# include <vector>
# include <queue>
# include <sys/time.h>
# include <cstdlib>
# include <limits.h>
# include <cstring>

class Pmerge{
	private :
		std::vector<int> vec;
		std::deque<int>  dq;
		long dVec;
		long dDq;
	public :
		Pmerge(const char **av);
		~Pmerge();
		Pmerge &operator=(const Pmerge &other);
		Pmerge(const Pmerge &other);
};

#endif
