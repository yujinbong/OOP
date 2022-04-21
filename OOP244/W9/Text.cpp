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
#include <fstream>
#include <cstring>
#include "Text.h"
#include "Utils.h"

using namespace std;
namespace sdds {

    Text::Text() {
        m_content = new char[1];
        m_content[0]='\0';
    }
    Text::Text(char* content) {
        if(content != nullptr)
        {
            ut.alocpy(m_content,content);
        }
        else
        {
            m_content = new char[1];
            m_content[0]='\0';
        }
    }

    Text::Text(Text& t) {
        ut.alocpy(m_content, t.m_content);
    }

    const char&Text:: operator[](int index) const {
        return m_content[index];
    }


    Text& Text :: operator+=(char content) {

        char *temp=new char[strlen(m_content)+2];

        strcpy(temp, m_content);
        temp[strlen(m_content)]=content;
        temp[strlen(m_content)+1]='\0';
        
        delete [] m_content;
        m_content=temp;
        return *this;
    }

    Text& Text:: operator=(Text& t) {
        delete[] m_content;
        m_content = nullptr;
        ut.alocpy(m_content, t.m_content);
        return *this;
    }

    Text::~Text() {
        delete[] m_content;
        m_content = nullptr;
    }

    void Text::read(istream& istr) {
        
        delete[] m_content;
        m_content = nullptr;
        int len = ut.getFileLength(istr);
        m_content = new char[len+1];
        
        for (int i = 0; i < len; i++){
            istr.get(m_content[i]);
            //cout << m_content[i] << endl;
        }

        m_content[len]='\0';
        
    }


    ostream& Text::write(ostream& ostr)const {
        ostr << m_content ;
        return ostr;
    }

    ostream& operator<<(ostream& ostr, const Text& t){
        t.write(ostr);
        return ostr;
    }

    istream& operator>>(istream& istr, Text& t) {
        t.read(istr);
        return istr;
    }

    
}
