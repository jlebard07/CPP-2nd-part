#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "fstream"

ShrubberyCreationForm::ShrubberyCreationForm(std::string str) : AForm::AForm("Shrubbery", 145, 137), target(str) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other){
	this->sign = other.getSigned();
	if (this->signGrade < 1)
		throw GradeTooHighException("Form's grade too high");
	else if (this->signGrade > 150)
		throw GradeTooLowException("Form's grade too low");
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other) : AForm::AForm(other), target(other.getTarget()) {}

std::string ShrubberyCreationForm::getTarget() const {
	return this->target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	if (!this->sign)
		throw (GradeTooHighException("Form " + this->name + " has not been signed yet"));
	if (this->execGrade < executor.getLvl())
		throw (GradeTooLowException("Bureaucrat " + executor.getName() + " has not the level required to execute " + this->name +" Form"));
	std::string nameF = this->target + "_shrubbery";
	std::ofstream outfile(nameF.c_str());
	if (outfile.good()){
		outfile <<
		"         v" << std::endl <<
		"        >X<" << std::endl <<
		"         A" << std::endl <<
		"        d$b" << std::endl <<
		"      .d\\$$b." << std::endl <<
		"    .d$i$$\\$$b." << std::endl <<
		"       d$$@b" << std::endl <<
		"      d\\$$$ib" << std::endl <<
		"    .d$$$\\$$$b" << std::endl <<
		"  .d$$@$$$$\\$$ib." << std::endl <<
		"      d$$i$$b" << std::endl <<
		"     d\\$$$$@$b" << std::endl <<
		"  .d$@$$\\$$$$$@b." << std::endl <<
		".d$$$$i$$$\\$$$$$$b." << std::endl <<
		"        ###" << std::endl <<
		"        ###" << std::endl <<
		"        ###" << std::endl <<
		std::endl;
	}
	else{
		std::cerr << "Can't establish ofstream" << std::endl;
		return ;
	}
	outfile.close();
}

void ShrubberyCreationForm::beSigned(const Bureaucrat &boss){
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
