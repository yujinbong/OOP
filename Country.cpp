/*
    ==================================================
    Workshop #4 (Part-1):
    ==================================================
    Name   : Yujin Bong
    ID     : 147525208
    Email  : ybong@myseneca.ca
    Section: NCC
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Country.h"
#include "City.h"
using namespace std;
namespace sdds {
    Country::Country(){
        //By default, a Country is initiated by setting all the member variable values to default values.
       // You can do this by setting m_name, m_city to nullptr and m_noOfCity to a recognizable value like 0.
        setEmpty();
    }

    Country::Country(const char* name, int noOfCity,const City* cities) {
        //First, it will set the attributes to default values (So if the argument validation fails, the object will be in a safe empty state)
        //Next, if all of the arguments are valid, it will set m_name and m_noOfCity to the corresponding argument values. The number of cities cannot be more than MAX_CITY and less than zero.
        //Then dynamically allocate an array of cities pointed by m_city member variable. The length of this array will be m_noOfCity.
        //Lastly, add all the cities to the dynamically allocated array of m_city.
        setEmpty();
        if (name != nullptr && strlen(name) >0 && noOfCity > 0 && noOfCity <= MAX_CITY) {
            // check!
            m_name = new char[strlen(name) + 1];
            strcpy(m_name, name);
            m_noOfCity = noOfCity;
            m_city = new City[noOfCity];
            for (int i = 0; i < noOfCity; i++)
                m_city[i] = cities[i];
        }
    }

        void Country::setName(const char* name){
            delete[] m_name;
            if(name != nullptr && strlen(name) > 0){
                m_name=new char[strlen(name)+1];
                strcpy(m_name,name);
            }
            else{
                delete[] m_city;
                setEmpty();
            }
        }

    Country& Country:: addCity(const City& c) {
        if (!c.isEmpty()) { // 더 좋은 방법 알아보기
            //If the incoming City reference is not empty, this method will add the city
            // to the m_city array of cities, otherwise, the function is exited and no action will be taken.
            City *temp = new City[m_noOfCity + 1];
            for (int i = 0; i < m_noOfCity; i++)
                temp[i] = m_city[i];
                delete[] m_city; // 필수!!!!
                temp[m_noOfCity] = c;
                m_city = temp;
                m_noOfCity++;
            }
            return *this;
        }
        Country& Country:: migrate(int people){
            for (int i = 0; i < m_noOfCity; i++) {
                if(m_city[i].getPeople() <POPULATION){
                    m_city[i].addPopulation(people);
            }
         }
            return *this;
        }
    void Country::setEmpty(){
        m_name= nullptr;
        m_noOfCity=0;
        m_city= nullptr;
    }
    bool Country::isEmpty()const {
       /* bool result = false;
        if (m_name == nullptr) result = true;
        else if ((m_name[0] == '\0') || ( m_noOfCity < 0)) result = true;
        return result;*/
       return (m_name == nullptr || m_name[0]=='\0');
    }

    Country::~Country(){
        //Deallocate the memory allocated by m_name and m_city.
        delete[] m_city;
        delete[] m_name;
    }
    void Country:: display()const{
        if(!isEmpty()){
        cout <<  "Country Name: ";
        cout << m_name << endl;
        cout <<  "No of city: ";
        cout << m_noOfCity << endl;
        cout << "City name";
        cout.width(33);
        cout.setf(ios::right);
        cout.unsetf(ios::right);
        cout << "Population"<<endl;
        for(int i=0;i<m_noOfCity;i++)
            m_city[i].display();
    }
        else cout<< "Invalid country object" << endl;

    }
    }







