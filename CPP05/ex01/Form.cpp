#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string str, int sign, int exec) : name(str), signGrade(sign), execGrade(exec) {
	this->sign = 0;
	if (this->signGrade < 1)
		throw GradeTooHighException("Form " + this->name + "'s grade too high");
	else if (this->signGrade > 150)
		throw GradeTooLowException("Form " + this->name + "'s grade too low");
}

Form::~Form() {}

Form::Form(const Form &other) : sign(other.sign), name(other.name), signGrade(other.signGrade), execGrade(other.execGrade) {
	if (this->signGrade < 1)
		throw GradeTooHighException("Form " + this->name + "'s grade too high");
	else if (this->signGrade > 150)
		throw GradeTooLowException("Form " + this->name + "'s grade too low");
}

Form &Form::operator=(const Form &other){
	this->sign = other.getSigned();
	std::cout << this;
	if (this->signGrade < 1)
		throw GradeTooHighException("Form's grade too high");
	else if (this->signGrade > 150)
		throw GradeTooLowException("Form's grade too low");
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
	return this->msg.c_str();
}

const char *Form::GradeTooLowException::what() const throw(){
	return this->msg.c_str();
}

void Form::beSigned(const Bureaucrat &boss){
	std::string str = this->name;
	std::string str2 = boss.getName();
	
	if (this->sign == 1){
		throw GradeTooLowException(name + " has already been signed");
	}
	else if (boss.getLvl() < this->signGrade){
		this->sign = 1;
		std::cout << this->name << " has been signed by " << boss.getName() << std::endl;
	}
	else{
		throw GradeTooLowException(str2 + " isn't important enough to sign " + str);
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
