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


