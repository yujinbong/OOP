#pragma once
#ifndef SDDS_COVIDCOLLECTION_H
#define SDDS_COVIDCOLLECTION_H
#include <string>
#include <vector>
namespace sdds {
	struct Covid {
		std::string m_country;
		std::string m_city;
		std::string m_variant;
		size_t m_noOfCases;
		int m_year;
		size_t m_noOfDeaths;
	};
	class CovidCollection
	{
		std::vector<Covid> m_covids;
	public:
		CovidCollection(std::string filename);
		void display(std::ostream& out) const;
	
	};
	std::ostream& operator<<(std::ostream& out, const Covid& theCovid);
}
#endif // !SDDS_COVIDCOLLECTION_H



