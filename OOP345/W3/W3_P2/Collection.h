// Workshop 3 - Templates
// 2022/01/28 - If this code works, it was created by Cornel
//            - If it doesn't work, I don't know who wrote it.
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef  SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iomanip>
#include <iostream>
#include "Pair.h"

namespace sdds {

	template<typename T, size_t capacity>
	class Collection  {
		T m_array[capacity]{};
		size_t m_noOfElement{};
		static T dummy;  //to save memory
	public:
		//part2
		~Collection() {}
		size_t size() const {
			return m_noOfElement;
		}
		void display(std::ostream& os = std::cout)const { 
			/*
			----------------------
			| Collection Content |
			----------------------
			16
			12
			9
			3
			21
			12
			23
			----------------------
	*/
			os <<  std::setfill('-') << std::setw(22) <<"-"<<std::endl;
			os << "| Collection Content |" << std::endl;
			os << std::setfill('-') << std::setw(22) << "-" << std::endl;
			for (size_t i = 0; i < m_noOfElement; i++) { 
				os << m_array[i] << std::endl;
			}
			os << std::setfill('-') << std::setw(22) << "-" << std::endl;
		}

		virtual bool add(const T& item) {
			bool flag = false;
		
			if (m_noOfElement < capacity) {
				m_array[m_noOfElement] = item;
				m_noOfElement++;
				flag =true;
		}
			return flag; 
		}
	
		T operator[](size_t index) const {
			return index >= 0 && index < m_noOfElement ? m_array[index] : dummy;
		}

	


		};

    template <typename T,size_t capacity>
	T Collection<T, capacity>::dummy{};

	template<>
	Pair Collection<Pair, 100>::dummy{ "No Key", "No Value" };

}


#endif // ! COLLECTION_H
