# include "Bureaucrat.hpp"
# include "Form.hpp"

int main(){
	try{
		Bureaucrat B1("Vladimir", 1);
		std::cout << B1 << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e){
		std::cerr << "Error" << e.what() << std::endl; 
	}
	catch (Bureaucrat::GradeTooLowException &e){
		std::cerr << "Error" << e.what() << std::endl; 
	}
	try{
		Bureaucrat B2("Stephane", 150);
		std::cout << B2 << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e){
		std::cerr << "Error" << e.what() << std::endl; 
	}
	catch (Bureaucrat::GradeTooLowException &e){
		std::cerr << "Error" << e.what() << std::endl; 
	}
	try{
		Bureaucrat B1("Vladimir", 1);
		std::cout << ++B1 << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e){
		std::cerr << "Error" << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e){
		std::cerr << "Error" << e.what() << std::endl; 
	}
	try{
		Bureaucrat B2("Stephane", 150);
		std::cout << --B2 << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e){
		std::cerr << "Error" << e.what() << std::endl; 
	}
	catch (Bureaucrat::GradeTooLowException &e){
		std::cerr << "Error" << e.what() << std::endl; 
	}
	Bureaucrat B1("Vladimir", 1);
	try{
		Bureaucrat B2 = B1;
		std::cout << B2 << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e){
		std::cerr << "Error" << e.what() << std::endl; 
	}
	catch (Bureaucrat::GradeTooLowException &e){
		std::cerr << "Error" << e.what() << std::endl; 
	}
}
