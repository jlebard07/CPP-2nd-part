#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string str, int sign, int exec) : name(str), signGrade(sign), execGrade(exec) {
	this->sign = 0;
	if (this->signGrade < 1)
		throw GradeTooHighException("Form " + this->name + "'s grade too high");
	else if (this->signGrade > 150)
		throw GradeTooLowException("Form " + this->name + "'s grade too low");
}

AForm::~AForm() {}

AForm::AForm(const AForm &other) : sign(other.sign), name(other.name), signGrade(other.signGrade), execGrade(other.execGrade) {
	if (this->signGrade < 1)
		throw GradeTooHighException("Form " + this->name + "'s grade too high");
	else if (this->signGrade > 150)
		throw GradeTooLowException("Form " + this->name + "'s grade too low");
}

AForm &AForm::operator=(const AForm &other){
	this->sign = other.getSigned();
	if (this->signGrade < 1)
		throw GradeTooHighException("Form's grade too high");
	else if (this->signGrade > 150)
		throw GradeTooLowException("Form's grade too low");
	return *this;
}

std::string AForm::getName() const{
	return this->name;
}

int AForm::getExeceGrade() const{
	return this->execGrade;
}

int AForm::getSignGrade() const{
	return this->signGrade;
}

bool AForm::getSigned() const{
	return this->sign;
}

const char *AForm::GradeTooHighException::what() const throw (){
	return this->msg.c_str();
}

const char *AForm::GradeTooLowException::what() const throw(){
	return this->msg.c_str();
}

void AForm::beSigned(const Bureaucrat &boss){
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

void AForm::execute(Bureaucrat const & executor) const {
	(void)executor;
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
