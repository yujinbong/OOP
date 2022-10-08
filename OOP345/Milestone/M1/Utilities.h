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

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <string>
namespace sdds {

	class Utilities {
		size_t m_widthField = 1; 
		static char m_delimiter;// separates the tokens
	public:
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		static void setDelimiter(char newDelimiter);

		static char getDelimiter();
	};

}


#endif
