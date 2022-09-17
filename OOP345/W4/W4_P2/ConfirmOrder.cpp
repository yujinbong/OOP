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
		//���� ���߿����� ��̿� ��� �ϳ��� ���̰� �ִ��� Ȯ��
		bool isFound = false;
		if (m_noOfChild > 0) { 
			for (size_t i = 0; i < m_noOfChild; i++)
			{
		       //m_toyArray[i] i��(�ڷ���) toy*(������ ������)
				if (m_toyArray[i] == &toy)//m_toyArray[i]�� toy���� ������ Ȯ���ϰ� ������ bool�� true�� ���� �� for�� ��������
					isFound = true;
			}
			if (!isFound)
			{
				const Toy** temp = m_toyArray; //temp��� Toy**�� �ӽð��� ���� �ϳ��� �߰��Ѵ�.
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
