#ifndef __ROBOTOMY__
# define __ROBOTOMY__

# include "Bureaucrat.hpp"
# include "AForm.hpp"

class Bureaucrat;

class AForm;

class RobotomyRequestForm : public AForm{
	private :
		std::string const _target;
	public :
		RobotomyRequestForm(std::string str);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		RobotomyRequestForm(const RobotomyRequestForm &other);

		std::string getTarget() const;
		void execute(Bureaucrat const & executor) const;
		void beSigned(const Bureaucrat &boss);

};

#endif