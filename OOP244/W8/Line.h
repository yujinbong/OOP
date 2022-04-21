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
#ifndef W8_LINE_H
#define W8_LINE_H

#include <iostream>
#include "LblShape.h"

namespace sdds {
    class Line  :public LblShape{
        int m_length;
    public:
        Line();
        Line(const char *label,int length);


        virtual void draw(ostream &os) const;
        virtual void getSpecs(istream &is);

    };

    //ostream &operator<<(ostream &os, const Line &s);
    //istream &operator>>(istream &is, Line &s);

}
#endif //W8_LINE_H
