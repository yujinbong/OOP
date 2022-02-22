/* ------------------------------------------------------
Workshop 5 part 1
 Student Name : Yujin Bong
Student ID : 147525208
Section : NDD
Professor : Arezoo Tony
Date : Feb.15
Module: Flightpp
Filename: Flight.c
Version 1.0
Date: 24/11/2021
Author: Asam Gulaid
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials    Date           Reason
F.S.        07/02/2022     Peer Review
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include "Flight.h"

using namespace std;
namespace sdds {

    void Flight::emptyPlane() {
        m_passengers = 0;
        m_fuel = 0;
        strcpy(m_title, "EmptyPlane");
    }

    // New Flight
    Flight::Flight() {
        emptyPlane();
    }

    Flight::~Flight() {
        emptyPlane();
    }

    Flight::Flight(int passengers, double fuel, const char *title) {
        emptyPlane();
        if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
            fuel <= FuelTankCapacity) {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title, title);
        }
    }

    std::ostream &Flight::display() const {

        if (*this) {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << string(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        } else if (~*this) {
            cout << " Flight  |  Empty Plane    ";
        } else {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char *) (*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }

    Flight::operator bool() const {
        return m_passengers > 0 && m_fuel >= m_passengers * UnitFuel;
    }

    Flight::operator int() const{
        return m_passengers;
    }

    Flight::operator double() const{
        return m_fuel;
    }

    Flight::operator const char *() const{
        return m_title;
    }

    bool Flight::operator ~() const{

        return m_passengers==0;
    }


    bool Flight::operator==(const Flight &right) const{

        return m_passengers == right.m_passengers
               && m_fuel == right.m_fuel
               && strcmp(m_title,right.m_title)==0;
    }

    Flight &Flight::operator=(int passengers){
        m_passengers=passengers;
        return *this;
    }

    Flight &Flight::operator=(double fuel){
        m_fuel = fuel;
        return *this;
    }

    Flight &Flight::operator+=(double fuel){
        m_fuel +=fuel;
        //m_fuel.operator +=(fuel);
        return *this;
    }

    Flight &Flight::operator+=(int passengers){
        m_passengers+=passengers;
        return *this;
    }

    Flight &Flight::operator-=(double fuel){
        m_fuel -= fuel;
        return *this;
    }

    Flight &Flight::operator-=(int passengers){
        m_passengers -= passengers;
        return *this;
    }

    Flight &Flight::operator >>(Flight &right)
    {
        right.m_passengers += m_passengers;
        if(Boen747Capacity <right.m_passengers)
        {
            m_passengers=right.m_passengers-Boen747Capacity;
            right.m_passengers=Boen747Capacity;
        }

        return *this;
    }

    Flight &Flight::operator=(const Flight &right)
    {
        m_passengers = right.m_passengers;
        m_fuel = right.m_fuel;
        strcpy(m_title,right.m_title);

        right.~Flight(); //avoid const

        return *this;
    }

    int operator+(int left,const Flight &right){
        return left+int(right);
    }

    int operator+=(int &left,const Flight &right){
        left+=int(right);
        return left;
    }

}
