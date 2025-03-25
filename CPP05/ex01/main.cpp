# include "Bureaucrat.hpp"
# include "Form.hpp"

int main(){
	Bureaucrat B1("Sarko", 1);
	Bureaucrat B2("Pas d'inspi", 100);
	Form F1("traite", 10, 2);
	Form F2("arrete", 90, 120);
	try{
		Form F3("random1", 151, 2);
		std::cout << F3 << std::endl;
	}
	catch (Form::GradeTooLowException &e){
		std::cerr << "Error : " << e.what() << std::endl;
	}
	try{
		Form F3("random2", 0, 2);
		std::cout << F3 << std::endl;
	}
	catch (Form::GradeTooHighException &e){
		std::cerr << "Error : " << e.what() << std::endl;
	}
	try{
		F1.beSigned(B1);
	}
	catch (Form::GradeTooLowException &e){
		std::cerr << "Error : " << e.what() << std::endl;
	}
	std::cout << F1;
	try{
		F1.beSigned(B2);
	}
	catch (Form::GradeTooLowException &e){
		std::cerr << "Error : " << e.what() << std::endl;
	}
	try{
		F2.beSigned(B2);
	}
	catch (Form::GradeTooLowException &e){
		std::cerr << "Error : " << e.what() << std::endl;
	}
}
