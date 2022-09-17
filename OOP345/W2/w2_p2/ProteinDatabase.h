// Workshop 2 - Copy and Move Semantics
// 2021/11/28 - Mufleh Al-Shatnawi
// Professor    : Chris Szalwinski
// Student      : Yujin Bong
// Student ID   : 147-525-208
// SECTIOMN     : NEE 
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_PROTEINDATABASE_H
#define SDDS_PROTEINDATABASE_H
#include <iostream>

namespace sdds {
	class ProteinDatabase {
		std::string* m_array{};
		size_t m_noOfString{};

	public:
		ProteinDatabase();
		ProteinDatabase(std::string str);
		ProteinDatabase(const ProteinDatabase& I);
		ProteinDatabase(ProteinDatabase&& I); //move constructor
		~ProteinDatabase();
		ProteinDatabase& operator=(const ProteinDatabase& p);
		ProteinDatabase& operator=(ProteinDatabase&& p); //move assignment operator
		size_t size() const;
		std::string operator[](size_t index) const;
	};



}
#endif
