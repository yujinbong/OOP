// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel
// 2021/01/19 - Chris
// 2021/02/12 - Cornel
// Name      : Yujin Bong
// Student ID   : 147-525-208
// SECTIOMN     : NEE 
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "SpellChecker.h"
#include <fstream>
#include <iomanip>



namespace sdds {


	sdds::SpellChecker::SpellChecker(const char* filename)
	{
		std::ifstream file(filename);
		if (!file) throw "Bad file name!"; //const char*
		else {
			size_t i = 0;
			do
			{
				file >> m_badWords[i] >> m_goodWords[i];
				i++;
			} while (i < 6 && file);
		}
	}

	void sdds::SpellChecker::operator()(std::string& text)
	{
		//for (size_t i = 0; i < 6; i++)
		//{
		//	for (size_t i = 0; i < 6 && m_badWords[i].length() != 0; i++) {
		//	m_replaceCounter[i]+=replace_all(text, m_badWords[i], m_goodWords[i]);
		//}
		//		// 1.badwords를 먼저 find함수로 찾은 후
		//		// 2.replace함수로 찾은 m_badwords길이를 구하고 길이만큼 good words로 replac한다.
		//	/*	string str = "helli world";
		//		string bad = "i";
		//		str.replace(str.find(bad), bad.length(), "o");
		//		cout << str << endl;   */
		//	}
		//}
		for (size_t i = 0; i < 6 && m_badWords[i].length() != 0; i++) {
			m_replaceCounter[i] += replace(text, m_badWords[i], m_goodWords[i]);
		}
	}


	size_t SpellChecker::replace(std::string& source, std::string badwords, std::string goodwords)
	{
		size_t count = 0;
		std::string::size_type pos = 0;
		while ((pos = source.find(badwords, pos)) != std::string::npos) {
			source.replace(pos, badwords.length(), goodwords);
			pos += goodwords.length();
			count++;
		}
		return count;
	}


	void sdds::SpellChecker::showStatistics(std::ostream& out) const
	{
		out << "Spellchecker Statistics" << std::endl;
		for (size_t i = 0; i < 6 && m_badWords[i].length() != 0; i++)
		{
			//            teh: 4 replacements
			out << std::setw(15) << std::right << m_badWords[i] << ": " << m_replaceCounter[i] << " replacements" << std::endl;
		}
	}
}