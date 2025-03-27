#ifndef __DYNAMIC__
# define __DYNAMIC__

# include <string>
# include <iostream>
# include <cstdlib>
# include <ctime>
# define nullptr 0

class Base{
	private :
	public :
		virtual ~Base();
};

class A : public Base{
	private :
	public :
		A();
		~A();	
};


class B : public Base{
	private :
	public :
		B();
		~B();
};


class C : public Base{
	private :
	public :
		C();
		~C();
};

#endif
