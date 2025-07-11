#include "RPN.hpp"

int operand(int a, int b, char op){
	if (op == '+')
		return a + b;
	if (op == '-')
		return a - b;
	if (op == '*')
		return a * b;
	if (op == '/'){
		if (b == 0)
			throw (std::runtime_error("Invalid RPN expression: division by zero"));
		return a / b;
	}
	return 1;
}

int RPN::getResult() const {
	if (stack.size() != 1)
		throw (std::runtime_error("Invalid RPN expression: too many operands left in stack"));
	return stack.top();
}

RPN::RPN(const char *str){
	while (*str){
		if (isspace(*str)){
			str++;
			continue;
		}
		else if (isdigit(*str)){
			if (*(str + 1) && isdigit(*(str + 1)))
				throw (std::runtime_error("Invalid RPN expression: two digits together"));
			stack.push(*str - '0');
			str++;
		}
		else if (*str == '+' || *str == '-' || *str == '*' || *str == '/'){
			if (stack.size() < 2)
				throw (std::runtime_error("Invalid RPN expression: not enough operands for operation"));
			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();
			int result = operand(a, b, *str);
			stack.push(result);
			str++;;
		}
	}
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
