#ifndef __PRESIDENTIAL__
# define __PRESIDENTIAL__

# include "Bureaucrat.hpp"
# include "AForm.hpp"

class AForm;

class Bureaucrat;

class PresidentialPardonForm : public AForm{
	private : 
		std::string _target;
	public :
		PresidentialPardonForm(std::string str);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
		PresidentialPardonForm(const PresidentialPardonForm &other);

		void beSigned(const Bureaucrat &boss);
		void execute(Bureaucrat const & executor) const;
};

#endif
