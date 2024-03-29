// Workshop 6 - STL Containers
// 2020/02/26 - Cornel
// Name      : Yujin Bong
// Student ID   : 147-525-208
// SECTIOMN     : NEE 
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include "Vehicle.h"
namespace sdds {
	class Car : public Vehicle
	{
		std::string m_maker{};
		std::string m_condition;
		double m_topspeed{};
	public:
		Car(std::istream& istr);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;

	};
	void trim(std::string& src);
}
#endif


