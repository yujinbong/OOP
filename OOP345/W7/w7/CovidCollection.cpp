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
					if (tempCovid.m_year < 0) tempCovid.m_year = 0;
				}
				catch (invalid_argument&) {
					tempCovid.m_year = 0;
				}
				tempCovid.m_noOfCases = stoi(temp.substr(80, 5));
				tempCovid.m_noOfDeaths = stod(temp.substr(85, 5));
				m_covids.push_back(tempCovid);
			}

		} while (file);
		file.close();
	}
	void CovidCollection::display(std::ostream& out) const
	{
		for_each(m_covids.begin(), m_covids.end(), [&out](const Covid& covid) {out << covid; }); //auto ¹Ù²Ù
	}
	std::ostream& operator<<(std::ostream& out, const Covid& theCovid)
	{
		out << "| " << setw(21) << left << theCovid.m_country << " | "
			<< setw(15) << left << theCovid.m_city << " | "
			<< setw(20) << left << theCovid.m_variant << " | " << setw(6) << right;
		if (theCovid.m_year == 0) out << ' ';
		else out << theCovid.m_year;
		out << " | " << setw(4) << theCovid.m_noOfCases << " | ";
		out << setw(3) << theCovid.m_noOfDeaths << " |" << endl;;
		return out;
	}
}