// Workshop 6 - STL Containers
// 2020/02/26 - Cornel
// Name      : Yujin Bong
// Student ID   : 147-525-208
// SECTIOMN     : NEE 
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#include "Racecar.h"

using namespace std;
namespace sdds {

	Racecar::Racecar(std::istream& in) : Car(in)
	{
		in.seekg(ios_base::beg);
		string str="";
		getline(in, str);
		str.erase(0, str.find_last_of(',') + 1);
		m_booster = stod(str);

	}

	void Racecar::display(std::ostream& out) const
	{
		Car::display(out);
		out << '*';
	}

	double Racecar::topSpeed() const
	{
		return Car::topSpeed() * (1 + m_booster);
	}

}
