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

#ifndef W8_LBLSHAPE_H
#define W8_LBLSHAPE_H

#define _CRT_SECURE_NO_WARNINGS
#include "Shape.h"
#include <iostream>
using namespace std;
namespace sdds {

    class LblShape :public Shape{
    protected:
        char* m_label= nullptr;
    public:
        LblShape();
        LblShape(LblShape &ls);
        LblShape(const char *label);
        LblShape &operator =(LblShape &ls);

        virtual void draw(ostream &os) const = 0;// pure virtual function
        virtual void getSpecs(istream &is);
        virtual ~LblShape(); // what is the virtual empty destructor?

    };

}
#endif //W8_LBLSHAPE_H
