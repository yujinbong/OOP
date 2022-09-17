// w4_p2.cpp - Containers
// 2021/12/02 - Miguel
// 2022/02/02 - Cornel
// Professor    : Chris Szalwinski
// Student      : Yujin Bong
// Student ID   : 147-525-208
// SECTIOMN     : NEE 
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "ConfirmOrder.h"


namespace sdds {
	sdds::ConfirmOrder::ConfirmOrder() : m_toyArray(nullptr)
	{
	}

	ConfirmOrder::ConfirmOrder(const ConfirmOrder& I)
	{
		*this = I;
	}

	ConfirmOrder::ConfirmOrder(ConfirmOrder&& I) noexcept
	{
		*this = std::move(I);
	}

	ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& other)
	{
		if (this != &other) {
			delete[] m_toyArray;
			m_noOfChild = other.m_noOfChild;
			m_toyArray = new const Toy * [m_noOfChild];
			for (size_t i = 0; i < m_noOfChild; i++)
			{
				m_toyArray[i] = other.m_toyArray[i];
			}
		}
		return *this;
	}

	ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& other) noexcept
	{
		if (this != &other) {
			delete[] m_toyArray;
			m_noOfChild = other.m_noOfChild;
			m_toyArray = other.m_toyArray;
			other.m_toyArray = nullptr;
			other.m_noOfChild = 0;
		}
		return *this;
	}

	ConfirmOrder::~ConfirmOrder()
	{
		delete[] m_toyArray;
	}

	ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy)
	{
		bool flag = false;
		if (m_noOfChild == 0) {
			m_toyArray = new const Toy * [1];
			//m_toyArray[m_noOfChild] = &toy;
			m_toyArray[0] = &toy;
			m_noOfChild++;
		}
		else if (m_noOfChild > 0) {
			for (size_t i = 0; i < m_noOfChild && !flag; i++)
			{
				if (m_toyArray[i] == &toy) flag = true;
			}
			if (!flag) {
				//ConfirmOrder temp = *this;
				const Toy** temp = m_toyArray;
				m_toyArray = new const Toy * [++m_noOfChild];
				for (size_t i = 0; i < m_noOfChild -1; i++)
				{
					m_toyArray[i] = temp[i];
				}
				delete[] temp;
				m_toyArray[m_noOfChild - 1] = &toy;
			}
		}
		return *this;
	}

	ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy)
	{
		int flag = -1;
		if (m_noOfChild > 0) {
			for (int i = 0; i < (int)m_noOfChild && flag < 0; i++)
			{
				if (m_toyArray[i] == &toy) flag = i;
			}
			if (flag >= 0) {
				//ConfirmOrder temp = *this;
				const Toy** temp = m_toyArray;
				//delete[] m_toyArray;
				m_toyArray = new const Toy * [--m_noOfChild];
				for (int i = 0; i < flag; i++)
				{
					//m_toyArray[i] = temp.m_toyArray[i];
					m_toyArray[i] = temp[i];
				}
				for (int i = flag; i < (int)m_noOfChild; i++)
				{
					m_toyArray[i] = temp[i + 1];
				}
				delete[] temp;
			}
		}
		return *this;
	}



	std::ostream& operator<<(std::ostream& os, const ConfirmOrder& c)
	{
		os << "--------------------------" << std::endl;
		os << "Confirmations to Send" << std::endl;
		os << "--------------------------" << std::endl;
		if (c.m_noOfChild == 0) {
			os << "There are no confirmations to send!" << std::endl;
		}
		else {
			for (size_t i = 0; i < c.m_noOfChild; i++)
			{
				os << *(c.m_toyArray[i]);
			}
		}
		os << "--------------------------" << std::endl;
		return os;
	}

}
