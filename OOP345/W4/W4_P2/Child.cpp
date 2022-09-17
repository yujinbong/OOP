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
			m_toyArray[i] = new Toy (*(m_toyArray[i]));
		}
	}

	Child& sdds::Child::operator=(const Child& other)
	{   //빈상태로 만들기 위해서는 Toy*와 Toy 둘의 요소 모두 지워줘야하기때문에,
		//for문에서하는건 -> Toy요소
		//delete[]는 Toy* 배열을 위해 삭제
        //copy의 경우에는 toy의 요소 하나하나를 복사해줘야하기때문에 동적할당을 해준 후 for문을 통하여 값을 하나하나 복사해야함.
		if (this != &other) {
			for (size_t i = 0; i < m_arraySize; i++)
			{
				delete m_toyArray[i];
			}
			delete[] m_toyArray;
		}
		m_childName = other.m_childName;
		m_age = other.m_age;
		m_toyArray = new Toy * [m_arraySize];
		for (size_t i = 0; i < m_arraySize; i++)
		{
			m_toyArray[i] = new const Toy (*(other.m_toyArray[i]));
		}
		return *this;
	}


	Child& sdds::Child::operator=(Child&& other) noexcept
	{
		//무브의 경우 복사를 할 필요없이 주소값을 가리키도록 하는것이기때문에 동적할당을 할필요없이 그냥
		//other로 받아온 값을 m_toyArray에 그대로 집어넣어주면된다.
		if (this != &other) {
			for (size_t i = 0; i < m_arraySize; i++)
			{
				delete m_toyArray[i];
			}
			delete[] m_toyArray;
			m_age = other.m_age;
			m_arraySize = other.m_arraySize;
			m_childName = other.m_childName;
			m_toyArray = other.m_toyArray;
			other.m_age={};
			other.m_arraySize = {};
			other.m_childName = {};
			other.m_toyArray = {};
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
		//
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