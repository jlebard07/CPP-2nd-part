#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string str) : AForm::AForm("Robotomy", 72, 45), _target(str) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
	this->sign = other.getSigned();
	if (this->signGrade < 1)
		throw GradeTooHighException("Form's grade too high");
	else if (this->signGrade > 150)
		throw GradeTooLowException("Form's grade too low");
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm::AForm(other), _target(other.getTarget()) {}

std::string RobotomyRequestForm::getTarget() const {
	return this->_target;
}

void RobotomyRequestForm::beSigned(const Bureaucrat &boss) {
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

long getTime(){
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_usec;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	if (!this->sign)
		throw (GradeTooHighException("Form " + this->name + " has not been signed yet"));
	if (this->execGrade < executor.getLvl())
		throw (GradeTooLowException("Bureaucrat " + executor.getName() + " has not the level required to execute " + this->name +" Form"));
	std::cout << "Vrrrrrrrrrr" << std::endl;
	std::srand(getTime());
	int nb = std::rand() % 2;
	if (nb == 0)
		std::cout << "Robotomy of target " << this->_target << " has failed" << std::endl;
	else
		std::cout << "Robotomy of target " << this->_target << " has been successfully completed" << std::endl;
}
