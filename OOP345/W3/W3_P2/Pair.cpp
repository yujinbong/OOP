// Workshop 3 - Templates
// 2022/01/28 - If this code works, it was created by Cornel
//            - If it doesn't work, I don't know who wrote it.
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include "Pair.h"
#include <iomanip>

namespace sdds {

	bool Pair::operator==(const Pair& p) const
	{
		return m_key == (p.m_key); 
	}

	std::ostream& operator<<(std::ostream& os, const Pair& p)
	{

	/*       static memory: memory allocated during the compilation time*/
		if (os) {
			os <<std::setfill(' ')<< std::setw(20) << std::right << p.m_key << ": " << p.m_value;
		}

		return os;
	}


}
