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