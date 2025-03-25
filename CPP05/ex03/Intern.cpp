#include "Intern.hpp"


Intern::Intern() {
	this->forms[0] = "request";
	this->forms[1] = "pardon";
	this->forms[2] = "shrubbery";
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &other) {
	(void)other;
	return *this;
}

Intern::Intern(const Intern &other){
	*this = other;
}

static AForm *makeShrubbery(const std::string target){
	return new ShrubberyCreationForm(target);
}

static AForm *makePardon(const std::string target){
	return new PresidentialPardonForm(target);
}

static AForm *makeRobotomy(const std::string target){
	return new RobotomyRequestForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target){
	AForm *(*all_forms[])(const std::string target) = {&makePardon, &makeRobotomy, &makeShrubbery};
	const char *names[] = {"pardon", "robotomy", "shrubbery"};

	for (int i = 0; i < 3; i++){
		if (name == names[i]){
			std::cout << "Intern creates " << name << std::endl;
			return (all_forms[i])(target);
		}
	}
	std::cout << "Cannot create " << name << " form" << std::endl;
	return NULL;
}
