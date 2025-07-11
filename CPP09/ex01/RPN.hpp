#ifndef __RPN_HPP__
# define __RPN_HPP__

# include <iostream>
# include <string>
# include <stack>

class RPN{
	private :
		std::stack<int> stack;
	public :
		RPN(const char *);
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();
		int getResult() const;
};

#endif
