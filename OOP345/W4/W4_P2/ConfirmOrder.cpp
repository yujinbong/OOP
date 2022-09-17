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
			other.m_noOfChild = {};
			other.m_toyArray = nullptr;
			
		}
		return* this;
	}

	ConfirmOrder::~ConfirmOrder()
	{
		delete[] m_toyArray;
	}

	ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy)
	{
		//현재 컨펌오더의 어레이에 적어도 하나의 토이가 있는지 확인
		bool isFound = false;
		if (m_noOfChild > 0) { 
			for (size_t i = 0; i < m_noOfChild; i++)
			{
		       //m_toyArray[i] i는(자료형) toy*(토이의 포인터)
				if (m_toyArray[i] == &toy)//m_toyArray[i]가 toy값과 같은지 확인하고 같으면 bool값 true로 변경 후 for문 빠져나옴
					isFound = true;
			}
			if (!isFound)
			{
				const Toy** temp = m_toyArray; //temp라는 Toy**의 임시값을 만들어서 하나씩 추가한다.
				m_toyArray = new const Toy * [m_noOfChild+1];
				for (size_t i = 0; i < m_noOfChild; i++)
				{
					m_toyArray[i] = temp[i];
				}
				m_toyArray[m_noOfChild++] = &toy;
				delete[] temp;
			}

		}
		else {
			m_toyArray = new const Toy * [1];
			m_toyArray[0] = &toy;
			m_noOfChild++;
		}
		
	}

	ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy)
	{
		bool isFound = false;
		
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
