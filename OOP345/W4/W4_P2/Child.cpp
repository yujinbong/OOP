// w4_p2.cpp - Containers
// 2021/12/02 - Miguel
// 2022/02/02 - Cornel
// Professor    : Chris Szalwinski
// Student      : Yujin Bong
// Student ID   : 147-525-208
// SECTIOMN     : NEE 
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "Child.h"

namespace sdds {

	sdds::Child::Child(std::string name, int age, const Toy* toys[], size_t count)
	{
		m_childName = name;
		m_age = age;
		m_arraySize = count;
		m_toyArray = new const Toy * [m_arraySize];
		for (size_t i = 0; i < m_arraySize; i++)
		{
			m_toyArray[i] = new Toy(*(toys[i]));   
		}
	}

	Child& sdds::Child::operator=(const Child& other)
	{
		if (this != &other)
		{
			for (size_t i = 0; i < m_arraySize; i++) // for문사용
			{
				delete m_toyArray[i];
			}
			delete[] m_toyArray;
			m_arraySize = other.m_arraySize;
			m_toyArray = new const Toy * [m_arraySize];
			for (size_t i = 0; i < m_arraySize; i++)
			{
				m_toyArray[i] = new Toy(*(other.m_toyArray[i]));
			}
			m_age = other.m_age;
			m_childName = other.m_childName;
		}
		return *this;
	}


	Child& sdds::Child::operator=(Child&& other) noexcept
	{
		if (this != &other)
		{
			for (size_t i = 0; i < m_arraySize; i++)
			{
				delete m_toyArray[i];
			}
			delete[] m_toyArray;
			m_arraySize = other.m_arraySize;
			m_toyArray = other.m_toyArray;
			m_age = other.m_age;
			m_childName = other.m_childName;
			other.m_toyArray = {}; // 소멸자가 호출될시 이동할 값의 메모리가 삭제되지않도록 임시객체 값 nullptr변경. 
			other.m_age = {};
			other.m_childName = {}; 
			other.m_arraySize = {};
		}
		return *this;
	}


	sdds::Child::Child(const Child& I)
	{
		*this = I;
	}

	sdds::Child::Child(Child&& I) noexcept
	{
		*this = std::move(I);
	}

	

	sdds::Child::~Child()
	{  
		for (size_t i = 0; i < m_arraySize; i++) {
			delete m_toyArray[i];
		}
		delete[] m_toyArray;
	}


	size_t sdds::Child::size() const
	{
		return m_arraySize;
	}

	std::ostream& operator<<(std::ostream& os, const Child& c)
	{
		static int cnt = 0;
		cnt++;

		os << "--------------------------" << std::endl;
		os << "Child " << cnt << ": " << c.m_childName << " " << c.m_age << " years old:" << std::endl;
		os << "--------------------------" << std::endl;
		if (c.size() == 0) {
			os << "This child has no toys!" << std::endl;
		}
		else {
			for (size_t i = 0; i < c.size(); i++)
			{
				os << *(c.m_toyArray[i]); // *
			}
		}
		os << "--------------------------" << std::endl;
		return os;
	}
}
