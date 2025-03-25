#ifndef __INTERN__
# define __INTERN__

# include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm;

class Intern{
	private :
		std::string forms[3];

	public :
		Intern();
		~Intern();
		Intern &operator=(const Intern &other);
		Intern(const Intern &other);

		AForm *makeForm(std::string name, std::string target);
};

#endif
