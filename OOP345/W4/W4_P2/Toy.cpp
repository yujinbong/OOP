// w4_p2.cpp - Containers
// 2021/12/02 - Miguel
// 2022/02/02 - Cornel
// Professor    : Chris Szalwinski
// Student      : Yujin Bong
// Student ID   : 147-525-208
// SECTIOMN     : NEE 
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iomanip>
#include <string.h>

#include "Toy.h"



 namespace sdds {
	 static double m_tax = 0.13; //﻿static variable is initialized only once.
	sdds::Toy::Toy()
	{

	}

	void sdds::Toy::update(int numItems)
	{
		 m_numItems = numItems;
		//std::cout << m_numItems << "엔드" << std::endl;
	}

	sdds::Toy::Toy(const std::string& toy)
	{  

		/*#ID:Name:NUM:PRICE
		1000121 : Red Bike : 1 : 89.99*/
		std::string temp = toy; 
		size_t id = std::stoi(temp); 
		temp.erase(0, temp.find(':') + 1);

		std::string name = temp.substr(0, temp.find(':'));
		trim(name);
		temp.erase(0, temp.find(':') + 1);

		int numItems = std::stoi(temp); //string to int
		temp.erase(0, temp.find(':') + 1);
		double price = std::stod(temp); ////string to double
		temp.erase(0, temp.find(':') + 1);


		m_orderId = id;
		m_name = name;
		m_numItems = numItems;
		m_price = price;
	}
	 
	
	void Toy::trim(std::string& src)
	{
		int begin = src.find_first_not_of(' ');
		int end = src.find_last_not_of(' ');

		src = src.substr(begin, end - begin + 1);
	}

	std::ostream& operator<<(std::ostream& os, const Toy toy)
	{
	    //Toy 1000121:          Red Bike  1 items   89.99/item  subtotal:  89.99 tax: 11.70 total: 101.6
		double subtotal = toy.m_numItems * toy.m_price;
		double tax =  (subtotal * m_tax * 100) / 100;
		os << "Toy";
		os << std::setw(8) << std::right << toy.m_orderId << ":";
		os << std::setw(18) << toy.m_name;
		os << std::setw(3) << toy.m_numItems<< " items";
		os << std::setw(8) << toy.m_price << "/item  subtotal:";
		os << std::setw(7) << subtotal;
		os << " tax:";
		os << std::setw(6)<<std::fixed << std::setprecision(2) << tax;
		os << " total:";
		os << std::setw(7) << std::setprecision(2) << tax + subtotal << std::endl;
		return os;
	}


 }
