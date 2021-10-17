/*
    ==================================================
    Workshop #4 (Part-1):
    ==================================================
    Name   : Yujin Bong
    ID     : 147525208
    Email  : ybong@myseneca.ca
    Section: NCC
*/

#ifndef OOPWORKSHOP_CITY_H
#define OOPWORKSHOP_CITY_H

#include <cstring>
#include <iomanip>


namespace sdds{
    const int POPULATION = 20000; //max population of a city
    class City{
    private:
        char m_cityName[31];// holds the city name up to 30 chars
        int m_population;//number of people. A city can have zero population.

    public:
        City();
        // By default a City is instantiated by setting all the member variables to default values.
        //You can do this by setting the first character of m_cityName to an empty Cstring and m_population to a value like -1.
        City(const char* name,int population);
        //A City can also be created by the city name and the number of population.
        //If name is not nullptr and not empty also if population is greater than or equal to zero (a city can have 0 population)
        // then it will set the received arguments to the corresponding member variables.
        // Otherwise, set the values to a safe empty state.
        void setEmpty();
        void setCityName(const char* name);
        void setPopulation(int population);
        void addPopulation(int population);
        bool isEmpty()const;
        int getPeople()const;
        void display()const;







    };





}
#endif //OOPWORKSHOP_CITY_H
