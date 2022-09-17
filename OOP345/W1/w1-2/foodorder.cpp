// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// Michael Huang - 2021/11/28
// Professor    : Chris Szalwinski
// Student      : Yujin Bong
// Student ID   : 147-525-208
// SECTIOMN     : NEE 
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include "foodorder.h"
#include <iomanip>
#include <cstring>
#include <string>

double g_taxrate;
double g_dailydiscount;

using namespace std;
namespace sdds {
	FoodOrder::FoodOrder()
	{
	}

	FoodOrder::FoodOrder(const FoodOrder& I)
	{
		*this = I;
	}
	FoodOrder::~FoodOrder()
	{
		delete[] m_foodDesc;
	}
	FoodOrder& FoodOrder::operator=(const FoodOrder& other)
	{

		if (this != &other) {
			delete[] m_foodDesc;
			strcpy(m_custName, other.m_custName);
			m_foodDesc = new char[strlen(other.m_foodDesc) + 1];
			strcpy(m_foodDesc, other.m_foodDesc);
			m_foodPrice = other.m_foodPrice;
			m_isDailySpecial = other.m_isDailySpecial;
		}
		else {
			delete[] m_foodDesc;
		}
		return *this;
	}

	void FoodOrder::read(std::istream& istr)
	{
		//Find the length of the string using the length function and then change the string to cstring using the c_str function.
		string str;
		//char foodDesc[25]{};
		char isDailySpecial='\0';
		istr.getline(m_custName, 9, ',');
		getline(istr, str, ',');
		delete[] m_foodDesc;
		m_foodDesc = new char[str.length() + 1];
		strcpy(m_foodDesc, str.c_str());
		//istr.getline(foodDesc, 24, ',');

		istr >> m_foodPrice;
		istr.ignore();
		istr >> isDailySpecial;
		if (isDailySpecial == 'Y') {
			m_isDailySpecial = true;
		}
		else {
			m_isDailySpecial = false;
		}

		//m_foodDesc = new char[strlen(foodDesc) + 1];
		//strcpy(m_foodDesc,foodDesc);
		//	cout << m_foodDesc << "12121212" << endl;
	}
	void FoodOrder::display() const
	{
		static int counter = 0;
		counter++;

		cout << setw(2) << left << counter << ". ";
		if (strlen(m_custName) != 0 && strlen(m_foodDesc) !=0) {
			cout << setw(10) << m_custName << "|";
			cout << setw(25) << m_foodDesc << "|";
			cout << setw(12) << fixed;
			cout.precision(2);
			cout << m_foodPrice * (1 + g_taxrate) << "|";
			cout << setw(13) << right;

			if (m_isDailySpecial) {
				cout << m_foodPrice * (1 + g_taxrate) - g_dailydiscount << endl;
			}
			else {
				cout << setfill(' ') << endl;
			}
		}
		else {
			cout << "No Order" << endl;
		}
	}
}
