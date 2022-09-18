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


#ifndef MS_1_DATE_H
#define MS_1_DATE_H

#include "Status.h"
#include <iostream>

namespace sdds {
    const int sdds_maxYear = 2030;

    class Date {
        int m_year = 0;//m_year >= 2022 && m_year <= maximumYearValue;
        int m_month = 0;// m_month >= 1 && m_month <= 12;
        int m_day = 0; //Day. 연도를 기준으로 월의 일 수와 1 사이의 정수입니다.
        Status m_state; //State; 날짜의 유효 상태를 유지하는 Status 개체입니다.
        bool m_formatted = false;  // a boolean value that is set to true to print the date as YYYY/MM/DD or false to print it as YYMMDD.
        //bool validate(int year, int month, int day, Status &s);//인수를 수신하지 않고 부울을 반환합니다.
        //ostream &printIDInfo(ostream &ostr) const;
        bool validate();

        //ostream &printIDInfo(ostream &ostr) const;
        void setdate(int year, int month, int day);

    public :
        Date();

        Date(int year, int month, int day);

        const sdds::Status &state() const {
            return m_state;
        }

        void formatted(bool flag);

        operator int() {
            return m_year * 372 + m_month * 31 + m_day;
        }

        ostream &print(ostream &ostr) const;

        istream &read(istream &istr);
    };

    ostream &operator<<(ostream &ostr, const Date &date);

    istream &operator>>(istream &istr, Date &date);
}

#endif //MS_1_DATE_H
