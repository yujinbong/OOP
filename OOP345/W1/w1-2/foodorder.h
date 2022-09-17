// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// Michael Huang - 2021/11/28
// Professor    : Chris Szalwinski
// Student      : Yujin Bong
// Student ID   : 147-525-208
// SECTIOMN     : NEE 
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_FOODORDER_H
#define SDDS_FOODORDER_H
#include <iostream>

extern double g_taxrate;
extern double g_dailydiscount;


namespace sdds {
	class FoodOrder {
		char m_custName[10]{};
		//char m_foodDesc[25]{}; part1
		char* m_foodDesc{};
		double m_foodPrice{};
		bool m_isDailySpecial{};


	public:
		FoodOrder();
		FoodOrder(const FoodOrder& I);
	    ~FoodOrder();
		FoodOrder& operator=(const FoodOrder& other);
		void read(std::istream& istr);
		void display() const; //<Customer Name>,<Order Description>,<Price>,<Daily Special Status>[newline]


	};
}
#endif
