#ifndef SDDS_PROTEINDATABASE_H
#define SDDS_PROTEINDATABASE_H



#include <iostream>
#include <string>
namespace sdds{
	

	class ProteinDatabase {
		std::string* m_stringArray = nullptr;
		size_t m_noOfString = 0;
	public:
		ProteinDatabase();
		ProteinDatabase(std::string str);
		ProteinDatabase(const ProteinDatabase& I);
		ProteinDatabase( ProteinDatabase&& I);
		~ProteinDatabase();
		ProteinDatabase& operator=(const ProteinDatabase& other);
		ProteinDatabase&& operator=(ProteinDatabase&& other);
		size_t size()const;
		std::string operator[](size_t index)const;
};


}


#endif // !SDDS)PROTEINDATABASE_H

