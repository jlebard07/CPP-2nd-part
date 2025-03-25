#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){
	Bureaucrat boss("boss", 149);
	try{
		ShrubberyCreationForm sh("outfile");
		std::cout << sh;
		sh.execute(boss);
	}
	catch (ShrubberyCreationForm::GradeTooHighException &e){
		std::cerr << e.what() << std::endl;
	}
	boss.setLvl(1);
	try{
		ShrubberyCreationForm sh("outfile");
		boss.signForm(sh);
		sh.execute(boss);
	}
	catch (ShrubberyCreationForm::GradeTooHighException &e){
		std::cerr << e.what() << std::endl;
	}
	catch (ShrubberyCreationForm::GradeTooLowException &e){
		std::cerr << e.what() << std::endl;
	}
	boss.setLvl(150);
	try{
		RobotomyRequestForm rb("Opposant politique");
		boss.signForm(rb);
		rb.execute(boss);
	}
	catch (RobotomyRequestForm::GradeTooHighException &e){
		std::cerr << e.what() << std::endl;
	}
	catch (RobotomyRequestForm::GradeTooLowException &e){
		std::cerr << e.what() << std::endl;
	}
	boss.setLvl(60);
	try{
		RobotomyRequestForm rb("Opposant politique");
		boss.signForm(rb);
		rb.execute(boss);
	}
	catch (RobotomyRequestForm::GradeTooHighException &e){
		std::cerr << e.what() << std::endl;
	}
	catch (RobotomyRequestForm::GradeTooLowException &e){
		std::cerr << e.what() << std::endl;
	}
	boss.setLvl(10);
	try{
		RobotomyRequestForm rb("Opposant politique");
		boss.signForm(rb);
		rb.execute(boss);
	}
	catch (RobotomyRequestForm::GradeTooHighException &e){
		std::cerr << e.what() << std::endl;
	}
	catch (RobotomyRequestForm::GradeTooLowException &e){
		std::cerr << e.what() << std::endl;
	}
	boss.setLvl(50);
	try{
		PresidentialPardonForm pp("Ravaillac");
		boss.signForm(pp);
		pp.execute(boss);
	}
	catch (PresidentialPardonForm::GradeTooHighException &e){
		std::cerr << e.what() << std::endl;
	}
	catch (PresidentialPardonForm::GradeTooLowException &e){
		std::cerr << e.what() << std::endl;
	}
	try{
		PresidentialPardonForm pp("Ravaillac");
		pp.execute(boss);
	}
	catch (PresidentialPardonForm::GradeTooHighException &e){
		std::cerr << e.what() << std::endl;
	}
	catch (PresidentialPardonForm::GradeTooLowException &e){
		std::cerr << e.what() << std::endl;
	}
	boss.setLvl(10);
	try{
		PresidentialPardonForm pp("Ravaillac");
		boss.signForm(pp);
		pp.execute(boss);
	}
	catch (PresidentialPardonForm::GradeTooHighException &e){
		std::cerr << e.what() << std::endl;
	}
	catch (PresidentialPardonForm::GradeTooLowException &e){
		std::cerr << e.what() << std::endl;
	}
	boss.setLvl(1);
	try{
		PresidentialPardonForm pp("Ravaillac");
		boss.signForm(pp);
		pp.execute(boss);
	}
	catch (PresidentialPardonForm::GradeTooHighException &e){
		std::cerr << e.what() << std::endl;
	}
	catch (PresidentialPardonForm::GradeTooLowException &e){
		std::cerr << e.what() << std::endl;
	}
}
