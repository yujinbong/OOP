// Workshop 2 - Copy and Move Semantics
// 2021/11/28 - Mufleh Al-Shatnawi
// Professor    : Chris Szalwinski
// Student      : Yujin Bong
// Student ID   : 147-525-208
// SECTIOMN     : NEE 
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include "ProteinDatabase.h"
#include <iostream>
#include <string>
#include <fstream>


using namespace std;
namespace sdds {
	


	ProteinDatabase::ProteinDatabase()
	{
	}

	ProteinDatabase::ProteinDatabase(std::string str)
	{
		size_t count = 0;
		char temp{};
		std::string tempStr{};
		std::ifstream fin(str);
		temp = fin.get();
		while (temp != std::istream::traits_type::eof()) {
			if (temp == '>') {
				count++;
				while ((temp = fin.get()) != '>' && temp != std::istream::traits_type::eof());
			}
		}
		m_noOfString = count;
		m_array = new std::string[m_noOfString + 1];    //필요없나?
		fin.clear(); 
		fin.seekg(0);
		for (size_t i = 0; i < m_noOfString; i++) {
			std::getline(fin, tempStr);
			while (fin.peek() != '>' && fin.peek() != std::istream::traits_type::eof()) {
				getline(fin, tempStr);
				m_array[i] += tempStr;
		   }

		}

	}

	ProteinDatabase::ProteinDatabase(const ProteinDatabase& I)
	{
		*this = I;
	}

	ProteinDatabase::ProteinDatabase(ProteinDatabase&& I)
	{
		*this = std::move(I);
	}

	ProteinDatabase::~ProteinDatabase()
	{
		delete[] m_array;
	}

	ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& p)
	{
		if (this != &p) {
			delete[] m_array;
			m_noOfString = p.m_noOfString;
			m_array = new std::string[m_noOfString];
			for (size_t i = 0; i < m_noOfString; i++)
			{
				m_array[i] = p.m_array[i];
			}
	   }

		return *this;
	}

	ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& p)
	{
		if (this != &p) {
			delete[] m_array;
			m_noOfString = p.m_noOfString;
			m_array = p.m_array;
			p.m_array = nullptr;
			p.m_noOfString = 0;
		}
		return *this;
	}

	size_t ProteinDatabase::size() const
	{
		return m_noOfString;
	}

	std::string ProteinDatabase::operator[](size_t index) const
	{
		return (index >= 0 && index < m_noOfString) ? m_array[index] : "";
	}


}
