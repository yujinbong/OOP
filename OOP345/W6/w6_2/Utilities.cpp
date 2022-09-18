// Workshop 6 - STL Containers
// 2020/02/26 - Cornel
// Name      : Yujin Bong
// Student ID   : 147-525-208
// SECTIOMN     : NEE 
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <string>
#include <sstream>
#include "Car.h"
#include "Racecar.h"
#include "Utilities.h"
using namespace std;
namespace sdds {
	Vehicle* createInstance(std::istream& in) 
	{
		Vehicle* Vehicle = nullptr;

		char tag = '\0';

		string str="";
		stringstream sstr;
		sstr.str("");
		getline(in, str);  //for read first sentence
		if (in.eof()) in.setstate(std::ios_base::failbit);
		sstr.str(str);//sting-> stream으로 바꿈(커서가 있을수있도록).->:Car(std::istream& istr
		streampos pos = sstr.tellg();
		sstr >> tag;
		sstr.seekg(pos);



		/* 공백땜에안됨.............!!!!!! 
	 in.peek();
	 if (in.peek() == 'c' || in.peek() == 'R') {
		 temp = new Racevar(sstr);
	 }
	 else {
		 throw tag;
	 }*/




		if (tag == 'c' || tag == 'C')
		{
			Vehicle = new Car(sstr);
		}
		else if (tag == 'r' || tag == 'R') {
			Vehicle = new Racecar(sstr);
		}
		else {
			throw tag;
		}


		return Vehicle;
	}
}