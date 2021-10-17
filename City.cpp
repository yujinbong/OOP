/*
    ===============================================
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
#include "City.h"
using namespace std;

namespace sdds {

   City::City(){
       //m_ncityName의 첫번쨰 문자를 빈 Cstring으로 설정 & m_population을 -1로 설정.
       setEmpty();
   }

   City::City(const char* name,int population){
       //이름이 nullptr이아니고 인구수가 0보다 크거나 같으면
      if(name != nullptr && population>=0){
          strcpy(m_cityName,name);
          m_population=population;
      }else{
          setEmpty();
      }
   }
   void City::setEmpty(){
       //Sets a City to a safe empty state by setting m_cityName to an empty string and m_population to -1.
       m_cityName[0]='\0';
       m_population=-1;
   }

    void City::setCityName(const char* name){

       if(name !=nullptr){
           strcpy(m_cityName,name);
       }else{
           m_cityName[0]='\0';
       }
   }
    void City::setPopulation(int population){
       //인구수가 max인구수보다 작으면 할당하고 아니면 -1
        if (population < POPULATION){
            m_population=population;
        }else{
        m_population=-1;
        }
   }
    void City::addPopulation(int population){
   // This function will add the newly migrated population to a city up to the constant POPULATION limit.
   // If the received value is less than POPULATION then it will add the value to that city. If after adding,
   // m_population exceeds value of the constant POPULATION
   // then it will set the m_population to POPULATION instead, discarding the population overflow.
        m_population += population;
        if(m_population > POPULATION)
            m_population = POPULATION;
    }
    bool City::isEmpty()const{
       //Returns true if m_cityName is empty or the m_population is less than 0.
        return (m_cityName[0] == '\0' || m_population < 0);
   }
    int City::getPeople()const{
       //Returns m_population
       return(m_population);
   }
    void City::display()const{
        if(!isEmpty()) {
            cout << "|";
            cout.width(30);
            cout.fill(' ');
            cout.setf(ios::left);
            cout << m_cityName;
            cout.unsetf(ios::left);
            cout << " | ";
            cout.width(10);
            cout.fill(' ');
            cout.setf(ios::right);
            cout << m_population;
            cout.unsetf(ios::right);
            cout << " | " << endl;
        }else{
            cout << "invalid city" << endl;
        }

    }
}
