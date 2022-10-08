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
#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <string>
namespace sdds {

	class Station {
		int m_stationID{};
		std::string m_nameOfItem{};
		std::string m_desc{};
		size_t m_nextSerialNo{};
		size_t m_noOfItems{};
		static size_t m_widthField; //static인 이유
		static int id_generator;
	public:
		Station(const std::string& str);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};

}

#endif
