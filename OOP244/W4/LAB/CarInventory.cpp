
/* ------------------------------------------------------
Workshop 4 part 1
Student Name : Yujin Bong
Email : ybong@myseneca.ca
Date:Feb.8
Student ID : 147525208
Section : NDD
Author: Asad Norouzi  Fall of 2021
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials   Date           Reason
F.S.	     04/02/2022     Added covered topics and simplifed.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "CarInventory.h"
using namespace std;

namespace sdds {

    CarInventory::CarInventory(){
        //cout << __FUNCTION__ << __LINE__<< endl;
        resetInfo();
    }


    CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price){
        setInfo(type,brand,model,year,code,price);
    }

    CarInventory::~CarInventory(){
        cout << __FUNCTION__ << __LINE__<< endl;
        delete [] m_type;
        delete [] m_brand;
        delete [] m_model;
    }

    void CarInventory::resetInfo()
    {

        m_type=nullptr;
        m_brand=nullptr;
        m_model=nullptr;
        m_year=2022;
        m_code=100;
        m_price=1;
    }

    CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price){
        //함수앞에 클래스
        //cout << __FUNCTION__ << __LINE__<< endl;
        delete [] m_type;
        delete [] m_brand;
        delete [] m_model;
        m_type=new char[strlen(type)+1];
        m_brand=new char[strlen(brand)+1];
        m_model=new char[strlen(model)+1];

        strcpy(m_type,type);
        strcpy(m_brand,brand);
        strcpy(m_model,model);
        m_year=year;
        m_code=code;
        m_price=price;

        return *this;
    }
//| SUV        | Volvo            | XC90             | 2019 |  109 |  80000.00 |
    void CarInventory::printInfo() const{
        cout << "| ";
        cout << left << setw(10) <<m_type;
        cout << " | ";
        cout << setw(16) <<m_brand;
        cout << " | ";
        cout << setw(16) <<m_model;
        cout << " | ";
        cout << setw(4) <<m_year;
        cout << " | ";
        cout << right <<setw(4) <<m_code;
        cout << " | ";
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << right << setw(9)<< m_price;
        cout << " |" << endl;

    }

    bool CarInventory::isValid() const{

        /*type, not null
        brand, not null
        model, not null
        year >= 1990
        code, three digit integer
        prince > 0*/

        return m_type !=nullptr && m_brand !=nullptr && m_model !=nullptr &&
               m_year >=1990 && m_code >=100 && m_code <1000 && m_price > 0;
    }

    bool CarInventory::isSimilarTo(const CarInventory& car) const{
        //cout << __FUNCTION__ << __LINE__<< endl;

        return strcmp(m_type,car.m_type) == 0 && strcmp(m_brand,car.m_brand) ==0  && strcmp(m_model,car.m_model)==0;
    }

    bool find_similar(CarInventory car[], const int num_cars){
        //cout << __FUNCTION__ << __LINE__<< endl;

        for(int i=0;i<num_cars;i++)
            for(int j=i+1;j<num_cars;j++)
            {
                if(car[i].isValid() && car[j].isValid() && car[i].isSimilarTo(car[j]))
                    return true;
            }
        return false;
    }





}
