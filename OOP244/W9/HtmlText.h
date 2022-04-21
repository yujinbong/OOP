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

#ifndef W9_HTMLTEXT_H
#define W9_HTMLTEXT_H
#include <iostream>
#include "Text.h"

using namespace std;
namespace sdds {

    class HtmlText : public Text {
        char* m_title;


    public:
        HtmlText();
        HtmlText(const char title[]);
        HtmlText(HtmlText& h);
        HtmlText &operator=(HtmlText &h);
        virtual ~HtmlText();
      //  istream &read(istream &istr);
        ostream &write(ostream &ostr) const;
    };
 ostream &operator<<(ostream &ostr, const HtmlText &t);
// istream &operator>>(istream &is, HtmlText &t);
}
#endif //W9_HTMLTEXT_H
