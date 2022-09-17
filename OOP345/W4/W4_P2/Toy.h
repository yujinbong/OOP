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
