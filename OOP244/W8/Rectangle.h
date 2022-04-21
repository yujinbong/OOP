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

#ifndef W8_RECTANGLE_H
#define W8_RECTANGLE_H
#include <iostream>
#include "LblShape.h"
namespace sdds {
    class Rectangle  :public LblShape{
        int m_length;
        int m_height;
    public:
        Rectangle();
        Rectangle(const char *label,int length,int height);

        virtual void draw(ostream &os) const;
        virtual void getSpecs(istream &is);

    };
    //  ostream &operator<<(ostream &os, const Rectangle &s);
    //istream &operator>>(istream &is, Rectangle &s);
}
#endif //W8_RECTANGLE_H
