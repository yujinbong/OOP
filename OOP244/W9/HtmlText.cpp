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
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <fstream>
#include "HtmlText.h"
#include "Utils.h"

using namespace std;
namespace sdds
{
    HtmlText::HtmlText()
    {
        m_title = nullptr;
    };
    HtmlText::HtmlText(const char title[])
    {
        if(title!=nullptr)
            ut.alocpy(m_title, title);
    }
    HtmlText::HtmlText(HtmlText &h) : Text(h)  ////////////////
    {
        m_title = nullptr;
        if(h.m_title!=nullptr)
            ut.alocpy(m_title, h.m_title);
        
    }
    HtmlText &HtmlText::operator=(HtmlText &h)
    {
        Text::operator=(h); ////////////////
        if(h.m_title!=nullptr)
            ut.alocpy(m_title, h.m_title);
        return *this;
    }

    HtmlText::~HtmlText()
    {
        delete[] m_title;
        m_title = nullptr;
    }

    ostream &HtmlText::write(ostream &ostr) const
    {
        bool ms = false;
        ostr <<"<html><head><title>" ;
        if(m_title !=nullptr){
            ostr<< m_title;
        }else{
            ostr << "No Title";
        }
        ostr <<"</title></head>\n<body>\n";
        if(m_title !=nullptr){
            ostr<<"<h1>" << m_title << "</h1>\n";
        }

       
        for (int i = 0; this->operator[](i) != 0; i++)
        {
            
            if(operator[](i)=='\n'){
              //operator[](i)=='\0';
              ostr <<"<br/>\n";
            
            }
            else if(i>0 && operator[](i-1)==' ' && operator[](i)==' '){
              //operator[](i)=='\0';
              ostr <<"&nbsp;";
            }
            else
            { // 한자리 공백은 여기에서 처리됨
                ostr << this->operator[](i);
            }
        }
        ostr << "</body>\n";
        ostr << "</html>";

        return ostr;
    }

    ostream &operator<<(ostream &ostr, const HtmlText &t)
    {
        t.write(ostr);
        return ostr;
    }

}
