// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel
// 2021/01/19 - Chris
// 2021/02/12 - Cornel
// Name      : Yujin Bong
// Student ID   : 147-525-208
// SECTIOMN     : NEE 
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "Movie.h"
#include <iomanip>

namespace sdds {

	Movie::Movie()
	{
	}

	const std::string& Movie::title() const
	{
		return m_title;
	}
	
	void Movie::trim(std::string& str)
	{
		int begin = str.find_first_not_of(' ');
		int end = str.find_last_not_of(' ');
		str = str.substr(begin, end - begin + 1);
	}

	Movie::Movie(const std::string& strMovie)
	{
		//Game of Thrones ,          2011,        Nine noble famillies begim fighting for control over teh mythical lands of Westeros.

		std::string temp = strMovie;
		std::string title = temp.substr(0, temp.find(',')); //Game of Thrones ,
		trim(title);//Game of Thrones,
		temp.erase(0, temp.find(',') + 1);//Game of Thrones

		int year = std::stoi(temp);//2011,
		temp.erase(0, temp.find(',') + 1); //2011

		std::string desctiption = temp; //Nine noble famillies begim fighting for control over teh mythical lands of Westeros.
		trim(desctiption);

		m_title = title;
		m_year = year;
		m_description = desctiption;
	}




	std::ostream& operator<<(std::ostream& os, const Movie& movie)
	{
		//                         Game of Thrones | 2011 | Nine noble famillies begim fighting for control over teh mythical lands of Westeros.
		os << std::setw(40) << std::right << movie.m_title << " | ";
		os << std::setw(4) << movie.m_year << " | ";
		os << movie.m_description << std::endl;
		return os;
	}


}