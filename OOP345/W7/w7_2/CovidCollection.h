// Workshop 7: STL Algorithms
// Name      : Yujin Bong
// Student ID   : 147-525-208
// SECTIOMN     : NEE 
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_COVIDCOLLECTION_H
#define SDDS_COVIDCOLLECTION_H
#include <string>
#include <vector>
#include <list>
namespace sdds {
	struct Covid {
		std::string m_country;
		std::string m_city;
		std::string m_variant;
		size_t m_noOfCases;
		int m_year;
		size_t m_deaths;
	};
	class CovidCollection
	{
		std::vector<Covid> m_covids;
	public:
		CovidCollection(std::string filename);
		void display(std::ostream& out) const;
		void sort(std::string field);
		void cleanList();
		bool inCollection(const std::string& variant) const;
		std::list<Covid> getListForCountry(const std::string& country) const;
		std::list<Covid> getListForVariant(const std::string& variant) const;
	};
	std::ostream& operator<<(std::ostream& out, const Covid& theCovid);
}
#endif // !SDDS_COVIDCOLLECTION_H



