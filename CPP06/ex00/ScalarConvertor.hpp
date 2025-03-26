#ifndef __SCALARCONVERTOR__
# define __SCALARCONVERTOR__

# include <iostream>
# include <string>
# include <cstdlib>

class ScalairConvertor{
	private :
		ScalairConvertor();
		~ScalairConvertor();
		ScalairConvertor(ScalairConvertor &other);
		ScalairConvertor &operator=(ScalairConvertor &other);
	public :
		static void convert(std::string str);
};

#endif
