
/*===============================================
Workshop #4 (Part-2):
==================================================
Name   : Yujin Bong
ID     : 147525208
Email  : ybong@myseneca.ca
        Section: NCC
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Chapter.h"
using namespace std;

namespace sdds {

    Chapter::Chapter(){ //default
        setEmpty();
    }

    Chapter::Chapter(const char *name, int pages) {
        if (name!=nullptr && name[0]!='\0' && pages > 0 && pages < PAGE) {
            strcpy(m_cname, name);
            m_cpages = pages;
        } else {
            setEmpty();
        }
    }
    void Chapter::setEmpty(){
        m_cname[0]='\0';
        //strcpy(m_cname,"");
        m_cpages=0;
    }
    void Chapter::setChapter(const char* name) {
        strcpy(m_cname, name);
    }
    void Chapter::setpage(const int pages) {
        if (pages <= PAGE) {
            m_cpages = pages; //
        } else {
            m_cpages = 1;
        }
    }
    /*
    void Chapter::addpages(int pages){
        m_cpages += pages;
        if(m_cpages > PAGE)
            m_cpages = PAGE; //오버플로우방지!!
    }
    */
    bool Chapter::isEmpty() const{
        return m_cname[0]=='\0';
    }
    int Chapter::getpage() const {
        return m_cpages;//필요한지 확인하기!!!
    }

    const char *Chapter::getChapter() const {
        return m_cname;//필요한지 확인하기!!!
    }

    void Chapter::display()const{
        if(!isEmpty()) {
            cout.width(50);
            cout.fill('.');
            cout.setf(ios::left);
            cout << m_cname;
            cout.unsetf(ios::left);
            cout.width(4);
            cout.fill(' ');
            cout.setf(ios::right);
            cout << m_cpages << endl;
            cout.unsetf(ios::right);

        }else{
            cout << "... any many more lines will be printed" << endl;
        }

    }



}








