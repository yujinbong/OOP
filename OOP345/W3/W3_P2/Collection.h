#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include "Pair.h"
namespace sdds {
	template<typename T, size_t CAPACITY>
	class Collection
	{
		T m_array[CAPACITY];
		size_t m_arraySize{};
		static T dummy;
	public:
		size_t size()const {
			return m_arraySize;
		}
		virtual ~Collection() {}
		void display(std::ostream& os = std::cout) const {
			os << "----------------------" << std::endl;
			os << "| Collection Content |" << std::endl;
			os << "----------------------" << std::endl;
			for (size_t i = 0; i < m_arraySize; i++) {
				os << m_array[i] << std::endl;
			}
			os << "----------------------" << std::endl;
		}
		virtual bool add(const T& item) {
			bool result = false;
			if (m_arraySize < CAPACITY) {
				m_array[m_arraySize] = item;
				m_arraySize++;
				result = true;
			}
			return result;
		}
		T operator[](size_t index) const {
			return (index >= 0 && index < m_arraySize) ? m_array[index] : dummy;
		}
		
	};

	template<class T, size_t CAPACITY>
	T Collection<T, CAPACITY>::dummy{};

	template<>
	Pair Collection<Pair, 100>::dummy{ "No Key", "No Value" };
}


#endif

