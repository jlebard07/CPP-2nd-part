#include "Form.hpp"

Form::Form(std::string str, int sign, int exec) : name(str), signGrade(sign), execGrade(exec) {
	std::cout << this;
	if (this->sign < 1)
		throw GradeTooHighException("Form's grade is too high !");
	else if (this->sign > 150)
		throw GradeTooLowException("Form's grade is too low !");
}

Form::~Form() {}

Form::Form(const Form &other) : name(other.name), sign(other.sign), signGrade(other.signGrade), execGrade(other.execGrade) {
	std::cout << this;
	if (this->sign < 1)
		throw GradeTooHighException("Form's grade is too high !");
	else if (this->sign > 150)
		throw GradeTooLowException("Form's grade is too low !");
}

Form &Form::operator=(const Form &other){
	this->sign = other.getSigned();
	std::cout << this;
	if (this->sign < 1)
		throw GradeTooHighException("Form's grade is too high !");
	else if (this->sign > 150)
		throw GradeTooLowException("Form's grade is too low !");
}

std::string Form::getName() const{
	return this->name;
}

int Form::getExeceGrade() const{
	return this->execGrade;
}

int Form::getSignGrade() const{
	return this->signGrade;
}

bool Form::getSigned() const{
	return this->sign;
}

Form::GradeTooHighException::GradeTooHighException(std::string str) : _errMsg(str) {}

Form::GradeTooLowException::GradeTooLowException(std::string str) : _errMsg(str) {}

const char *Form::GradeTooHighException::what() const throw (){
	return this->_errMsg.c_str();
}

const char *Form::GradeTooLowException::what() const throw(){
	return this->_errMsg.c_str();
}

void Form::beSigned(const Bureaucrat &boss){
	if (this->sign == 1){
		throw GradeTooHighException("Form" + this->name + "is already signed");
	}
	else if (boss.getLvl() < this->signGrade){
		this->sign = 1;
		std::cout << this->name << "has been signed by " << boss.getName() << std::endl;
	}
	else{
		throw GradeTooLowException(boss.getName() + "'s lvl is not high enough too sign" + this->name);
	}
}

std::ostream &operator<<(std::ostream &os, const Form &form){
	os << "Name of form : " << form.getName() << "\nLevel to sign : " << form.getSignGrade() << "\nLevel to execute : " << form.getExeceGrade() << "\nIs signed ? ";
	if (form.getSigned() == 1)
		os << "Yes";
	else
		os << "No"; 
}
