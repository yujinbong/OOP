// Final Project
// Milestone 1
// ms1_prof.cpp
// Winter 2021
// Chris Szalwinski
// Student Name: Yujin Bong
// Seneca Student ID: 147-525-208
// Seneca email:ybong@myseneca.ca
// Date of completion: July.21
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#include "Utilities.h"
using namespace std;
namespace sdds {
	char Utilities::m_delimiter{};


	void sdds::Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}

	size_t sdds::Utilities::getFieldWidth() const
	{
		return m_widthField;
	}

	void trim(string& src)
	{
		if (src.length() > 0) {
			int begin = src.find_first_not_of(' ');
			int end = src.find_last_not_of(' ');
			if (begin == -1) src = "";
			else src = src.substr(begin, end - begin + 1);
		}
	}

	std::string sdds::Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		int next_del;
		string result;
		if (str[next_pos] == m_delimiter)
		{
			more = false;
			throw - 1;
		}
		else {
			string temp = str.substr(next_pos);//시작인덱스-끝까지  ( 이부분 질문하기 size_t )
			if ((next_del = temp.find_first_of(m_delimiter)) != -1) { //공백이아니면
				result = temp.substr(0, next_del); //0에서 시작 next_del길이만큼
				trim(result);
				next_pos += next_del + 1;
				more = true;
			}
			else {
				result = temp;
				trim(result);
				more = false;
			}
		}
		if (m_widthField < result.length())
			m_widthField = result.length();

		return result;
	}

	void sdds::Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}

	char sdds::Utilities::getDelimiter()
	{
		return m_delimiter;
	}

}
