// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel
// 2021/01/19 - Chris
// 2021/02/12 - Cornel
// Name      : Yujin Bong
// Student ID   : 147-525-208
// SECTIOMN     : NEE 
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include <string>

namespace sdds {

	class Book {
		std::string m_author{};
		std::string m_title{};
		std::string m_country{};
		size_t m_year{};
		double m_price{};
		std::string m_description{};
		void trim(std::string& src);

	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		void updatePrice(double price);
		Book(const std::string& strBook);
		template<typename T> //part2
		void fixSpelling(T& spellChecker) {
			spellChecker(m_description); //SpellChecker::operator()함수호출
//ASSUMPTION: In this design, type T must have an overload of the operator() that accepts a string as a parameter.
		}

		friend std::ostream& operator <<(std::ostream& os, const Book& book);
	};

}
#endif // !SDDS_BOOK_H
