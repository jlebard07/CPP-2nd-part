#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string str) : AForm::AForm("Pardon", 25, 5), _target(str) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other){
	this->sign = other.getSigned();
	if (this->signGrade < 1)
		throw GradeTooHighException("Form's grade too high");
	else if (this->signGrade > 150)
		throw GradeTooLowException("Form's grade too low");
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm::AForm(other){
	if (this->signGrade < 1)
		throw GradeTooHighException("Form " + this->name + "'s grade too high");
	else if (this->signGrade > 150)
		throw GradeTooLowException("Form " + this->name + "'s grade too low");
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	if (!this->sign)
		throw (GradeTooHighException("Form " + this->name + " has not been signed yet"));
	if (this->execGrade < executor.getLvl())
		throw (GradeTooLowException("Bureaucrat " + executor.getName() + " has not the level required to execute " + this->name +" Form"));
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

void PresidentialPardonForm::beSigned(const Bureaucrat &boss) {
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

std::ostream &operator<<(std::ostream &os, const AForm &Aform){
	os << "Name of form : " << Aform.getName() << "\nLevel to sign : " << Aform.getSignGrade() << "\nLevel to execute : " << Aform.getExeceGrade() << "\nIs signed ? ";
	if (Aform.getSigned() == 1)
		os << "Yes";
	else
		os << "No";
	os << std::endl;
	return os;
}
