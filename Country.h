/*
    ==================================================
    Workshop #4 (Part-1):
    ==================================================
    Name   : Yujin Bong
    ID     : 147525208
    Email  : ybong@myseneca.ca
    Section: NCC
*/

#ifndef OOPWORKSHOP_COUNTRY_H
#define OOPWORKSHOP_COUNTRY_H
#include <cstring>
#include "City.h"

namespace sdds{
    const int MAX_CITY = 20; //maximum number of cities
    class Country{
    private:
        char* m_name;//points to a dynamically allocated Cstring holding the Country name
        int m_noOfCity;//size of the dynamically allocated array of cities
        // char m_cityName[31];// holds the city name up to 30 chars
        // int m_population;//number of people. A city can have zero population.
        City* m_city=nullptr;//pointer to the dynamically allocated array of cities

    public:
        Country();
        Country(const char* name, int noOfCity,const City* cities);
        void setName(const char* name);
        Country& addCity(const City& c);
        Country& migrate(int people);
        void setEmpty();
        bool isEmpty()const;
        ~Country();
        void display()const;
    };





}
#endif //OOPWORKSHOP_COUNTRY_H
