#ifndef __SHRUBERRYCREATIONFORM__
# define __SHRUBERRYCREATIONFORM__

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class AForm;

class Bureaucrat;

class ShrubberyCreationForm : public AForm{
	private :
		const std::string target;
	public :
		ShrubberyCreationForm(std::string str);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		ShrubberyCreationForm(ShrubberyCreationForm &other);

		void execute(Bureaucrat const & executor) const;
		void beSigned(const Bureaucrat &boss);
		std::string getTarget() const;
};

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &AForm);

#endif
