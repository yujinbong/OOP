/*
Final project Milestone 1
 Filename: Date.cpp
name: Yujin Bong
student ID :147525208
SECTION : NDD
PROFESSOR : Arezoo.tony
Date: 2022/03/13
Author: Fardad Soleimanloo   2022-02-28
Revision History
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <ctime>
#include "Date.h"
#include "Utils.h"

using namespace std;
namespace sdds {

    Date::Date() {
        // cout << __FUNCTION__ <<endl;
        int year;
        int month;
        int day;

        ut.getSystemDate(&year,&month,&day);
        setdate(year,month,day);
        m_formatted = true;
    }

    Date::Date(int year, int month, int day) {
        //   cout << __FUNCTION__ <<endl;
        setdate(year,month,day);
        m_formatted = true;
    }

    void Date::setdate(int year, int month, int day) {
        //   cout << __FUNCTION__ <<endl;
        m_year = year;
        m_month = month;
        m_day = day;
    }


    bool Date::validate() {
        m_state.clear();
        //cout << "validate" << m_year << " "<< m_month <<" " << m_day << endl;
        if (m_year < sdds_testYear || m_year > sdds_maxYear) {
            m_state = "Invalid year in date";
            m_state = 1;
            return false;
        }
        if (m_month < 1 || m_month > 12) {
            m_state = "Invalid month in date";
            m_state = 2;
            return false;
        }

        if (m_day<1 || m_day>ut.daysOfMon(m_month,m_year))
        {
            m_state = "Invalid day in date";
            m_state = 3;
            return false;
        }
        return true;
    }

    istream &Date::read(istream &istr)
    {
        int val;
        istr >> val;
        m_state.clear();
        if (istr) {
            {
                int year=val/10000;
                int month=val/100%100;
                int day=val%100;

                if(year==0)
                    year=2022;
                else
                    year+=2000;

                setdate(year,month,day);
                if(!validate())
                {
                    istr.setstate(ios_base::badbit);
                }

            }
        } else {
            m_state = "Invalid date value";
            //istr.clear();
        }
        //istr.ignore(1000, '\n');
        return istr;
    }



    ostream &Date::print(ostream &ostr) const {
        if (!m_formatted) {

            ostr.width(2);
            ostr.fill('0');
            ostr << m_year%100;
            ostr.width(2);
            ostr.fill('0');
            ostr << m_month;
            ostr.width(2);
            ostr.fill('0');
            ostr << m_day;

            //ostr<<setw(2)<<m_year<<endl;

        } else {
            ostr.width(4);
            ostr.fill('0');
            ostr << m_year << "/";
            ostr.width(2);
            ostr.fill('0');
            ostr << m_month << "/";
            ostr.width(2);
            ostr.fill('0');
            ostr << m_day;
        }


        return ostr;
    }

//여기확인
    void Date::formatted(bool flag) {
        m_formatted = flag;
    }

    ostream &operator<<(ostream &ostr, const Date &date) {
        // cout << __FUNCTION__ <<endl;
        date.print(ostr);
        return ostr;
    }

    istream &operator>>(istream &istr, Date &date) {
        //  cout << __FUNCTION__ <<endl;
        date.read(istr);
        return istr;
    }

}
