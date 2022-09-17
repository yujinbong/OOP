// w4_p2.cpp - Containers
// 2021/12/02 - Miguel
// 2022/02/02 - Cornel
// Professor    : Chris Szalwinski
// Student      : Yujin Bong
// Student ID   : 147-525-208
// SECTIOMN     : NEE 
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef  SDDS_CONFIRMORDER_H
#define   SDDS_CONFIRMORDER_H
#include <iostream>
#include <string>
#include "Toy.h"

namespace sdds {
	class ConfirmOrder {
		const sdds::Toy** m_toyArray{};
		size_t m_noOfChild{};

	public:
		ConfirmOrder();
		ConfirmOrder(const ConfirmOrder& I);
		ConfirmOrder(ConfirmOrder&& I) noexcept;
		ConfirmOrder& operator=(const ConfirmOrder& other);
		ConfirmOrder& operator=(ConfirmOrder&& other) noexcept;
		~ConfirmOrder();
		ConfirmOrder& operator+=(const Toy& toy);
		ConfirmOrder& operator-=(const Toy& toy);
		friend std::ostream& operator<<(std::ostream& os, const ConfirmOrder& c);
	};


}


#endif
