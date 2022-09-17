#ifndef  SDDS_CHILD_H
#define  SDDS_CHILD_H
#include <iostream>
#include "Toy.h"
namespace sdds {

	class Child {
		std::string m_childName{};
		int m_age{};
		const sdds::Toy** m_toyArray{};
		size_t m_arraySize{};

	public:
		
		Child(std::string name, int age, const Toy* toys[], size_t count);
		Child(const Child& I);
		Child(Child&& I) noexcept;
		Child& operator=(const Child& other);
		Child& operator=(Child&& other) noexcept;
		~Child();
		size_t size() const;
		friend std::ostream& operator<<(std::ostream& os, const Child& c);
	};

}

#endif