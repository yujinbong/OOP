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
	{   //����·� ����� ���ؼ��� Toy*�� Toy ���� ��� ��� ��������ϱ⶧����,
		//for�������ϴ°� -> Toy���
		//delete[]�� Toy* �迭�� ���� ����
        //copy�� ��쿡�� toy�� ��� �ϳ��ϳ��� ����������ϱ⶧���� �����Ҵ��� ���� �� for���� ���Ͽ� ���� �ϳ��ϳ� �����ؾ���.
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
		//������ ��� ���縦 �� �ʿ���� �ּҰ��� ����Ű���� �ϴ°��̱⶧���� �����Ҵ��� ���ʿ���� �׳�
		//other�� �޾ƿ� ���� m_toyArray�� �״�� ����־��ָ�ȴ�.
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