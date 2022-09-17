// w4_p2.cpp - Containers
// 2021/12/02 - Miguel
// 2022/02/02 - Cornel
// Professor    : Chris Szalwinski
// Student      : Yujin Bong
// Student ID   : 147-525-208
// SECTIOMN     : NEE 
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
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
