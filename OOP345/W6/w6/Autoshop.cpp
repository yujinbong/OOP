#include "Autoshop.h"
#include "Autoshop.h"

namespace sdds {

	Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
	{
		m_vehicles.push_back(theVehicle);
		return *this;
	}

	Autoshop::Autoshop()
	{
	}

	void Autoshop::display(std::ostream& out) const
	{
		out << "--------------------------------" << std::endl;
		out << "| Cars in the autoshop!        |" << std::endl;
		out << "--------------------------------" << std::endl;
		for (const auto& car : m_vehicles) {
			car->display(out);
			out << std::endl;
		}
		out << "--------------------------------" << std::endl;
	}

	Autoshop::~Autoshop()
	{
		for (auto& v : m_vehicles) delete v;

	}

}
