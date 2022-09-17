// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel
// 2021/01/19 - Chris
// 2021/02/12 - Cornel
// Name      : Yujin Bong
// Student ID   : 147-525-208
// SECTIOMN     : NEE 
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "Book.h"
#include <iomanip>

namespace sdds {
	Book::Book()
	{
	}

	const std::string& sdds::Book::title() const
	{
		return m_title;
	}

	const std::string& sdds::Book::country() const
	{
		return m_country;
	}

	void Book::updatePrice(double price)
	{
		m_price = price;
	}

	const size_t& sdds::Book::year() const
	{
		return m_year;
	}

	double& Book::price()
	{
		return m_price;
	}

	Book::Book(const std::string& strBook)
	{
		//Miguel de Cervantes,     Don Quixote,     Spain,    9.99,    1612,   The story follows a Hidalgo, Alonso Quixano, who proves that chivalry will in fact never die.

		std::string temp = strBook; //받아온 문자열을 temp에 임시로 저장한다.
		std::string author = temp.substr(0, temp.find(',')); // ','을 지우기 위해 substr을 이용하여 0번째 인덱스부터 find함수로 ','을 찾아내어 문자열을 추출한 후 autor 변수에 저장한다.
		trim(author); //만든 trim 함수로 author변수의 앞뒤의 공백을 지운다.

		temp.erase(0, temp.find(',') + 1); // ','뒤까지 문자를 지운다.

		std::string title = temp.substr(0, temp.find(','));
		trim(title);
		temp.erase(0, temp.find(',') + 1);

		std::string country = temp.substr(0, temp.find(','));
		trim(country);
		temp.erase(0, temp.find(',') + 1);

		double price = std::stod(temp);
		temp.erase(0, temp.find(',') + 1);
		int year = std::stoi(temp);
		temp.erase(0, temp.find(',') + 1);

		std::string description = temp;
		trim(description);
		m_author = author;
		m_title = title;
		m_country = country;
		m_year = year;
		m_price = price;
		m_description = description;

	}

	void Book::trim(std::string& str)
	{
		int begin = str.find_first_not_of(' ');
		int end = str.find_last_not_of(' ');
		str = str.substr(begin, end - begin + 1);
	}

	std::ostream& operator<<(std::ostream& os, const Book& book)
	{
		// Miguel de Cervantes |            Don Quixote | Spain | 1612 |   9.99 | The story follows a Hidalgo, Alonso Quixano, who proves that chivalry will in fact never die.

		os << std::setw(20) << std::right << book.m_author << " | ";
		os << std::setw(22) << book.m_title << " | ";
		os << std::setw(5) << book.m_country << " | ";
		os << std::setw(4) << book.m_year << " | ";
		os << std::setw(6) << std::fixed << std::setprecision(2) << book.m_price << " | ";
		os << book.m_description << std::endl;
		return os;
	}
}