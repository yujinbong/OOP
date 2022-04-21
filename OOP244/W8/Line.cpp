/* ------------------------------------------------------
Workshop 8 part 1
 //name: Yujin Bong
//SECTION : NCC
//PROFESSOR : Arezoo.tony
Module: N/A
Filename: main.cpp
Version 1
Author: Fardad Soleimanloo  22/03/17
Revision History
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date       Reason
-----------------------------------------------------------*/

#include "Line.h"
#include <iostream>
using namespace std;
namespace sdds {


    Line::Line()
    {
        m_length=0;
    }

    Line::Line(const char *label,int length) : LblShape(label)  // 초기화 리스트
    {
        m_length=length;
    }

    void Line::getSpecs(istream &is)
    {
        LblShape::getSpecs(is);
        is >> m_length;
        is.ignore(256,'\n');
    }

    void Line::draw(ostream &os)const
    {
        if (m_label == nullptr)
            return;


        if(m_length<=1)
            return;

        os << m_label << endl;
        for (int i = 0; i < m_length; i++)
            os << "=";

    }


}
