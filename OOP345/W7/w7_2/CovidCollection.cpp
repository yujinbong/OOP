// Workshop 7: STL Algorithms
// Name      : Yujin Bong
// Student ID   : 147-525-208
// SECTIOMN     : NEE 
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include "CovidCollection.h"
using namespace std;
namespace sdds {

	void trim(string& src)
	{
		if (src.length() > 0) {
			int begin = src.find_first_not_of(' ');
			int end = src.find_last_not_of(' ');
			if (begin == -1) src = "";
			else src = src.substr(begin, end - begin + 1);
		}
	}

	CovidCollection::CovidCollection(std::string filename)
	{
		ifstream file(filename);
		if (!file)
		{
			cerr << "ERROR: Cannot open the file named " << filename << endl;
			exit(-1);
		}
		Covid tempCovid;
		string temp;
		do
		{
			getline(file, temp);
			if (file) {
				tempCovid.m_country = temp.substr(0, 25);
				trim(tempCovid.m_country);
				tempCovid.m_city = temp.substr(25, 25);
				trim(tempCovid.m_city);
				tempCovid.m_variant = temp.substr(50, 25);
				trim(tempCovid.m_variant);
				try {
					tempCovid.m_year = stoi(temp.substr(75, 5));
					if (tempCovid.m_year < 0) tempCovid.m_year = 0; //아니면 0!!!
				}
				catch (invalid_argument&) { //아규먼트 꼭 넣기
					tempCovid.m_year = 0;
				}
				tempCovid.m_noOfCases = stoi(temp.substr(80, 5));
				tempCovid.m_deaths = stoi(temp.substr(85, 5));
				m_covids.push_back(tempCovid);
			}
		} while (file);
		file.close();
	}
	void CovidCollection::display(std::ostream& out) const
	{
		size_t total_cases = 0;
		size_t total_deaths = 0;
		for_each(m_covids.begin(), m_covids.end(), [&](const Covid& covid)
			{	out << covid << endl;
		total_cases += covid.m_noOfCases;
		total_deaths += covid.m_deaths;
			});
		cout << "----------------------------------------------------------------------------------------" << endl;
		cout << "|                                                 Total Cases Around the World: ";
		cout << setw(6) << total_cases << " |" << endl;
		cout << "|                                                Total Deaths Around the World: ";
		cout << setw(6) << total_deaths << " |" << endl;
	}
	void CovidCollection::sort(std::string field)
	{
		std::sort(m_covids.begin(), m_covids.end(), [&](const Covid& c1, const Covid& c2) {
			if (field == "country")	return c1.m_country < c2.m_country;
			else if (field == "variant") return c1.m_variant < c2.m_variant;
			else if (field == "cases") return c1.m_noOfCases < c2.m_noOfCases;
			else if (field == "deaths") return c1.m_deaths < c2.m_deaths;
			else return c1.m_country < c2.m_country; //아니면 country sort 
			});
	}
	void CovidCollection::cleanList()
	{
		Covid temp;
		replace_if(m_covids.begin(), m_covids.end(), [&temp](const Covid& covid) {
			temp = covid;
			temp.m_variant = "";
			return covid.m_variant == "[None]";
			}, temp);
	}

	bool CovidCollection::inCollection(const std::string& variant) const
	{
		return any_of(m_covids.begin(), m_covids.end(), [&variant](const Covid& covid) {return covid.m_variant == variant; });
	}

	std::list<Covid> CovidCollection::getListForCountry(const std::string& country) const
	{
		std::list<Covid> covidList(m_covids.size());
		auto it = copy_if(m_covids.begin(), m_covids.end(), covidList.begin(), [&country](const Covid& covid) {return covid.m_country == country; });
		covidList.resize(std::distance(covidList.begin(), it));
		return covidList;
	}

	std::list<Covid> CovidCollection::getListForVariant(const std::string& variant) const
	{
		std::list<Covid> covidList(m_covids.size());
		auto it = copy_if(m_covids.begin(), m_covids.end(), covidList.begin(), [&variant](const Covid& covid) {return covid.m_variant == variant; });
		covidList.resize(std::distance(covidList.begin(), it));
		return covidList;
	}


	std::ostream& operator<<(std::ostream& out, const Covid& theCovid)
	{
		out << "| " << setw(21) << left << theCovid.m_country << " | "
			<< setw(15)  << theCovid.m_city << " | "
			<< setw(20)<< theCovid.m_variant << " | " << setw(6) << right;
		if (theCovid.m_year == 0) out << ' ';
		else out << theCovid.m_year;
		out << " | " << setw(4) << theCovid.m_noOfCases << " | ";
		out << setw(3) << theCovid.m_deaths << " |";
		return out;
	}
}
