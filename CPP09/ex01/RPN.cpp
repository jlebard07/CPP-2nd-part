#include "RPN.hpp"

void checkRPN(const char *str, std::stack<int> stack){
	int count = 0;

	while (*str){
		if (*str == '*' || *str == '/' || *str == '+' || *str == '-')
			count++;
		str++;
	}
	if (count != stack.size() - 1) {
		throw (std::runtime_error("Invalid RPN expression: wrong number of operators"));
	}
	
}

RPN::RPN(const char *str){
	while (*str){
		if (!isdigit(*str)){
			str++;
			continue;
		}
		else {
			if (*(str + 1) && isdigit(*(str + 1)))
				throw (std::runtime_error("Invalid RPN expression: two digits together"));
			stack.push(*str - '0');
		}
	}
	if (stack.size() < 2)
		throw (std::runtime_error("Invalid RPN expression: not enough operands"));
	checkRPN(str, stack);
}

RPN::~RPN(){
}

RPN::RPN(const RPN &other) : stack(other.stack) {
	*this = other;
}

RPN &RPN::operator=(const RPN &other) {
	if (this != &other) {
		stack = other.stack;
	}
	return *this;
}
