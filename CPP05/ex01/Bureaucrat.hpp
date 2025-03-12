#ifndef __BUREAUCRAT__
# define __BUREAUCRAT__

# include <iostream>
# include <string>
# include "Form.hpp"

class Bureaucrat{
	private :
		const std::string name;
		int lvl;
	public :
		Bureaucrat(std::string name, int nb);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		
		Bureaucrat &operator=(const Bureaucrat &other);
		Bureaucrat &operator++();
		Bureaucrat &operator--();

		int getLvl() const;
		std::string getName() const;
		void signForm(Form &form);

		class GradeTooHighException : public std::exception{
			public :
				virtual const char* what() const throw();	
		};
		class GradeTooLowException : public std::exception{
			public :
				virtual const char* what() const throw();
		};
};
	
std::ostream &operator<<(std::ostream &os, const Bureaucrat &Bureaucrat);

#endif