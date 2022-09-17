
 // Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel
// 2021/01/19 - Chris
// 2021/02/12 - Cornel
// Name      : Yujin Bong
// Student ID   : 147-525-208
// SECTIOMN     : NEE 
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <iostream>
namespace sdds {
	class SpellChecker {
		
		std::string m_badWords[6]{};
		std::string m_goodWords[6]{};
		size_t m_replaceCounter[6]{};
		std::size_t replace(std::string& inout, std::string badwords, std::string goodwords);

	public:
		SpellChecker(const char* filename); // recevies the address of a C-style

		void operator()(std::string& text); // count how many times each misspelled word has been replaced.
		void showStatistics(std::ostream& out) const;


	};



}
#endif // !SDDS_SPELLCHECKER_H
