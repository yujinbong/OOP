#include <iomanip>
#include "Pair.h"
using namespace std;
namespace sdds {
	bool Pair::operator==(const Pair& other) const
	{
		return m_key == other.m_key;
	}
	std::ostream& operator<<(std::ostream& os, const Pair& pair)
	{
		os << setw(20) << right << pair.m_key << ": " << pair.m_value;
		return os;
	}
}