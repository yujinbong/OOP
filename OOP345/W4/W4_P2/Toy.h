// w4_p2.cpp - Containers
// 2021/12/02 - Miguel
// 2022/02/02 - Cornel
// Professor    : Chris Szalwinski
// Student      : Yujin Bong
// Student ID   : 147-525-208
// SECTIOMN     : NEE 
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef  SDDS_TOY_H
#define  SDDS_TOY_H
#include <iostream>
#include <string>


namespace sdds {

	class Toy {
		size_t m_orderId{};
		std::string m_name{};
		int m_numItems{};
		double m_price{};
		static double m_tax; //Initialize -> cpp file

	public:
		Toy();
		void update(int numItems);
		Toy(const std::string& toy);
		void trim(std::string& src);
		friend std::ostream& operator<<(std::ostream& os, const Toy toy);
	};



}
#endif // ! SDDS_YODY_H
