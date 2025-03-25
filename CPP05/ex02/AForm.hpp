#ifndef __AFORM__
# define __AFORM__

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
	protected :
		bool sign;
		const std::string name;
		const int signGrade;
		const int execGrade;
	public :
		AForm(std::string str, int sign, int exec);
		virtual ~AForm();
		AForm &operator=(const AForm &other);
		AForm(const AForm &other);

		std::string getName() const;
		int getSignGrade() const;
		int getExeceGrade() const;
		bool getSigned() const;
		void execute(Bureaucrat const & executor) const;

		virtual void beSigned(const Bureaucrat &boss) = 0;

		class GradeTooHighException : public std::exception{
			private :
				std::string msg;
			public :
				GradeTooHighException(std::string str) : msg(str) {}
				const char *what() const throw();
				virtual ~GradeTooHighException() throw() {}
		};
		class GradeTooLowException : public std::exception{
			private :
				std::string msg;
			public :
				GradeTooLowException(std::string str) : msg(str) {}
				const char *what() const throw();
				virtual ~GradeTooLowException() throw() {}
		};

};
	
std::ostream &operator<<(std::ostream &os, const AForm &AForm);

#endif