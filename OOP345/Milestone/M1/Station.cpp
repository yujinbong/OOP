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
#include <iostream>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"


using namespace std;
using namespace sdds;

namespace sdds {
	size_t Station::m_widthField = 0;
	int Station::id_generator = 0;
	Station::Station(const std::string& str)
	{
		//Armchair,    654321,  10,  Upholstered Wing Chair
		size_t pos = 0;
		bool more = true;
		Utilities util;
		m_stationID = ++id_generator;
		try {
			m_nameOfItem = util.extractToken(str, pos, more);
			m_nextSerialNo = stoi(util.extractToken(str, pos, more));
			m_noOfItems = stoi(util.extractToken(str, pos, more));
			Station::m_widthField = Station::m_widthField > util.getFieldWidth() ? Station::m_widthField : util.getFieldWidth();
			m_desc = util.extractToken(str, pos, more);
		}
		catch (std::invalid_argument& e) {
			throw e;
		}


	}
	const std::string& Station::getItemName() const
	{
		return m_nameOfItem;
	}
	size_t Station::getNextSerialNumber()
	{
		return m_nextSerialNo++;
	}
	size_t Station::getQuantity() const
	{
		return m_noOfItems;
	}
	void Station::updateQuantity()
	{
		if (m_noOfItems >= 1)
			m_noOfItems--;
	}
	void Station::display(std::ostream& os, bool full) const
	{
		//001 | Armchair        | 654321 |
		//cout << m_widthField <<"여기"<<endl;
		os <<  setw(3) << setfill('0') << right << m_stationID
			<< " | " << setw(m_widthField+1) << setfill(' ') << left << m_nameOfItem 
			<< " | " << setw(6) << right << setfill('0') << m_nextSerialNo << " | ";
		if (full) {
			os  << setw(m_widthField) << setfill(' ') << setw(4)<<right << m_noOfItems<<
				" | " << m_desc;
		}
		os << endl;
	}
}
