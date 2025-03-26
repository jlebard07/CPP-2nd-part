#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(){
	Intern someRandomIntern;
	AForm *rrf;
	rrf = someRandomIntern.makeForm("robotomy", "Bender");
	std::cout << *rrf;
	delete rrf;
	rrf = someRandomIntern.makeForm("pardon", "Bender");
	std::cout << *rrf;
	delete rrf;
	rrf = someRandomIntern.makeForm("shrubbery", "Bender");
	std::cout << *rrf;
	delete rrf;
	rrf = someRandomIntern.makeForm("wrong form", "Bender");
}
