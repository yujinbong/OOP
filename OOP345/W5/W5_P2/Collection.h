// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel
// 2021/01/19 - Chris
// 2021/02/12 - Cornel
// Name      : Yujin Bong
// Student ID   : 147-525-208
// SECTIOMN     : NEE 
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <string>
namespace sdds {
	template<typename T>
	class Collection {
		std::string m_name;
		T* m_array{};
		size_t m_size{};
		void (*m_observer)(const Collection<T>&, const T&) {};// 함수지만 변수

	public:	
		Collection(const std::string& name) :m_name(name)
		{
		} //만약 완성하면 private에서 변수 초기화해도되는지 확인하기
		Collection(const Collection& I) = delete;
		Collection(Collection&& I) = delete;
		Collection& operator = (const Collection& other) = delete;
		Collection& operator = (Collection&& other) = delete;
		~Collection() {
			delete[] m_array;
		}

		Collection<T>& operator+=(const T& item) {
			bool flag = false;
			if (m_size == 0) {
				m_array = new T[1];
				m_array[m_size] = item;
				m_size++;
			}
			else if (m_size > 0) {
				for (size_t i = 0; i < m_size && !flag; i++) {
					if (m_array[i].title() == item.title()) flag = true;
				}
				if (!flag) {
					T* temp = new T[m_size];
					for (size_t i = 0; i < m_size; i++) {
						temp[i] = m_array[i];
					}
					delete[] m_array;
					m_array = new T[++m_size];
					for (size_t i = 0; i < m_size - 1; i++) {
						m_array[i] = temp[i];
					}
					delete[] temp;
					m_array[m_size - 1] = item;
					if (m_observer != nullptr) m_observer(*this, item);
				}
			}
			return *this;
		}

		const std::string& name() const {
			return m_name;
		}
		size_t size() const {
			return m_size;
		}
		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			m_observer = observer; //library.setObserver(bookAddedObserver);
		}

		T& operator[](size_t idx) const {
			if (idx < 0 || idx >= m_size) {
				throw std::out_of_range(std::string("Bad index [") + std::to_string(idx) + std::string("]. Collection has [") + std::to_string(m_size) + std::string("] items."));
			}
			else {
				return m_array[idx];
			}
		}


		T* operator[](const std::string& title) const {
			int isFound = -1;

			for (size_t i = 0; i < m_size && isFound == -1; i++)
			{
				if (m_array[i].title() == title) {
					isFound = i;
				}
			}
			return isFound >= 0 ? &(m_array[isFound]) : nullptr;
		}


	};
	template<typename T>
	std::ostream& operator<<(std::ostream& os, const Collection<T>& collection) {
		for (size_t i = 0; i < collection.size() ; i++) {
			os << collection[i];
		}
		return os;
	}



}
#endif // !SDDS_COLLECTION_H

