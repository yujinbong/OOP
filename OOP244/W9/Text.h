/* ------------------------------------------------------
Workshop 9 part 1
 //name: Yujin Bong
//student ID :147525208
//SECTION : NCC
//PROFESSOR : Arezoo.tony
Module: N/A
Filename: main.cpp
Version 1
Author: Fardad Soleimanloo  22/04/17
Revision History
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date       Reason
-----------------------------------------------------------*/
#ifndef W9_TEXT_H
#define W9_TEXT_H

#include <iostream>

using namespace std;
namespace sdds {

    class Text {
    private:
        char* m_content = nullptr;

    protected:
        const char& operator[](int index) const ;


    public:
        Text();
        Text(char* content);
        Text(Text& t);
        Text& operator=(Text& t);
        Text& operator+=(char content);
        virtual ~Text();

        void read(istream& istr);
        ostream& write(ostream& ostr)const;



    };
   
    ostream& operator<<(ostream& ostr, const Text& t);
    istream& operator>>(istream& istr, Text& t);
}
#endif //W9_TEXT_H
