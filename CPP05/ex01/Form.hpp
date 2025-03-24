#ifndef __FORM__
# define __FORM__

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
	private :
		bool sign;
		const std::string name;
		const int signGrade;
		const int execGrade;
	public :
		Form(std::string str, int sign, int exec);
		~Form();
		Form &operator=(const Form &other);
		Form(const Form &other);

		std::string getName() const;
		int getSignGrade() const;
		int getExeceGrade() const;
		bool getSigned() const;

		void beSigned(const Bureaucrat &boss);

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
	
std::ostream &operator<<(std::ostream &os, const Form &form);

#endif