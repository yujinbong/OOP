
#ifndef SDDS_SET_H
#define SDDS_SET_H
#include <tgmath.h>
namespace sdds {
	template <typename T>
	class Set : public Collection<T, 100>{

	public:
		bool add(const T& item) {
			bool isFound = false;
			bool result = false;
			for (size_t i = 0; i < Collection<T,100>::size(); i++) {
				if ((*this)[i] == item) isFound = true;
			}
			if (!isFound) {
				result = Collection<T, 100>::add(item);
			}
			return result;
		}
	};

	template<>
	bool Set<double>::add(const double& item) {
		bool isFound = false;
		bool result = false;
		for (size_t i = 0; i < Collection<double, 100>::size(); i++) {
			if (fabs((*this)[i] - item) <= 0.01) isFound = true;
		}
		if (!isFound) {
			result = Collection<double, 100>::add(item);
		}
		return result;
	}

}


#endif // !SDDS_SET_H

