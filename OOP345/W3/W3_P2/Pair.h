// Workshop 3 - Templates
// 2022/01/28 - If this code works, it was created by Cornel
//            - If it doesn't work, I don't know who wrote it.
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef  SDDS_PAIR_H
#define SDDS_PAIR_H
#include <iostream>


namespace sdds {
	 
	class Pair
	{
		std::string m_key{};
		std::string m_value{};
	public: 
		const std::string& getKey() { return m_key; }
		const std::string& getValue() { return m_value; }
		Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value }{}

		// TODO: Add here the missing prototypes for the members
		//           that are necessary if this class is to be used
		//           with the template classes described below.
		//           Implement them in the Pair.cpp file.

		Pair() {} //default Constructor
		bool operator==(const Pair & p)const;
		friend std::ostream& operator<<(std::ostream& os, const Pair& p);

	};


}

#endif // ! SDDSPAIR_H
