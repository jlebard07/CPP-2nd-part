#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string str, int nb) : name(str){
	std::cout << "Bureaucrat constructor called" << std::endl;
	this->lvl = nb;
	if (this->lvl < 1)
		throw GradeTooLowException();
	if  (this->lvl > 150)
		throw GradeTooHighException();
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.getName()){
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	this->lvl = other.getLvl();
	if (this->lvl < 1)
		throw GradeTooLowException();
	if  (this->lvl > 150)
		throw GradeTooHighException();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	this->lvl = other.getLvl();
	if (this->lvl < 1)
		throw GradeTooLowException();
	if  (this->lvl > 150)
		throw GradeTooHighException();
	return *this;
}

void Bureaucrat::setLvl(int n){
	this->lvl = n;
}

Bureaucrat &Bureaucrat::operator++(){
	this->lvl -= 1;
	if  (this->lvl < 1)
		throw GradeTooHighException();
	return *this;
}

Bureaucrat &Bureaucrat::operator--(){
	this->lvl += 1;
	if (this->lvl > 150)
		throw GradeTooLowException();
	return *this;
}

int Bureaucrat::getLvl() const{
	return this->lvl;
}

std::string Bureaucrat::getName() const{
	return this->name;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Bureaucrat's grade is too high !";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "Bureaucrat's grade is too low !";
}

void Bureaucrat::signForm(AForm &form){
	form.beSigned(*this);
}

void Bureaucrat::executeForm(AForm const & form){
	form.execute(*this);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &Bureaucrat){
	os << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getLvl();
	return os;
}
