#include <string>
#include <sstream>
#include "Car.h"
//#include "Racecar.h"
#include "Utilities.h"
using namespace std;
namespace sdds {
	Vehicle* createInstance(std::istream& in)
	{
		Vehicle* result = nullptr;

		char vType = '\0';

		string str;
		stringstream sstr;
		getline(in, str);
		if (in.eof()) in.setstate(std::ios_base::failbit);
		sstr.str(str);
		streampos pos = sstr.tellg();
		sstr >> vType;
		sstr.seekg(pos);


		if (vType == 'c' || vType == 'C')
		{
			result = new Car(sstr);
		}
		/*else if (vType == 'r' || vType == 'R') {
			result = new Racecar(sstr);
		}*/
		else {
			throw vType;
		}


		return result;
	}
}
