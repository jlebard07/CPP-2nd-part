#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string str, int sign, int exec) : name(str), signGrade(sign), execGrade(exec) {
	this->sign = 0;
	if (this->signGrade < 1)
		throw GradeTooHighException();
	else if (this->signGrade > 150)
		throw GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form &other) : sign(other.sign), name(other.name), signGrade(other.signGrade), execGrade(other.execGrade) {
	if (this->signGrade < 1)
		throw GradeTooHighException();
	else if (this->signGrade > 150)
		throw GradeTooLowException();
}

Form &Form::operator=(const Form &other){
	this->sign = other.getSigned();
	std::cout << this;
	if (this->signGrade < 1)
		throw GradeTooHighException();
	else if (this->signGrade > 150)
		throw GradeTooLowException();
	return *this;
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

const char *Form::GradeTooHighException::what() const throw (){
	return "Form's grade too high";	
}

const char *Form::GradeTooLowException::what() const throw(){
	return "Form's grade too low";
}

void Form::beSigned(const Bureaucrat &boss){
	if (this->sign == 1){
		throw GradeTooHighException();
	}
	else if (boss.getLvl() < this->signGrade){
		this->sign = 1;
		std::cout << this->name << "has been signed by " << boss.getName() << std::endl;
	}
	else{
		throw GradeTooLowException();
	}
}

std::ostream &operator<<(std::ostream &os, const Form &form){
	os << "Name of form : " << form.getName() << "\nLevel to sign : " << form.getSignGrade() << "\nLevel to execute : " << form.getExeceGrade() << "\nIs signed ? ";
	if (form.getSigned() == 1)
		os << "Yes";
	else
		os << "No";
	return os;
}
