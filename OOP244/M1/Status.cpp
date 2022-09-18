/*
Final project Milestone 1
 Filename:Status.cpp
name: Yujin Bong
student ID :147525208
SECTION : NDD
PROFESSOR : Arezoo.tony
Date: 2022/03/13
Author: Fardad Soleimanloo   2022-02-28
Revision History
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Status.h"

using namespace std;
namespace sdds {

    void Status::set(const char *description) {
        //  cout << __FUNCTION__ << endl;
        //m_code = 0;

        if (description!=nullptr) {
            clear();
            m_description = new char[strlen(description) + 1];
            strcpy(m_description, description);
        } else
        {
            m_description = nullptr;
        }
    }

    Status::Status(const char *description) {
        //cout << __FUNCTION__ << " default constrructor"<<endl;
        m_description=nullptr;
        set(description);
    }

    Status::Status(const Status &s) {
        //cout << __FUNCTION__ << " copy constrructor"<<endl;
        m_description=nullptr;
        set(s.m_description);
        m_code=s.m_code;
    }

    Status &Status::operator=(const Status &s) {
        //cout << __FUNCTION__ << " opeator =" <<endl;
        if (this != &s) {
            set(s.m_description);
            m_code=s.m_code;
        }
        return *this;
    }


    Status::~Status() {
        //  cout << __FUNCTION__ << endl;
        clear();
    }
    ////

    Status &Status::clear() {

        /*Clear() 메서드입니다.
        설명을 안전하게 할당 취소하고 코드를 0으로 설정하는 clear()라는 메서드를 만듭니다.
        이 메서드는 끝에 있는 현재 개체에 대한 참조를 반환합니다.*/
        //if(m_description)
        //{
        //cout << __FUNCTION__ << endl;
        delete[] m_description;
        m_description = nullptr;
        //}
        m_code = 0;
        return *this;
    }

    Status &Status::operator=(const char *description) {
        // cout << __FUNCTION__ << "CHAR" << endl;
        set(description);
        return *this;
    }

    Status &Status::operator=(int code) {
        //cout << __FUNCTION__ << "INT" << endl;

        m_code = code;
        //cout << m_code << "여기"<< endl;
        return *this;
    }

    Status::operator bool() const {
        //   cout << __FUNCTION__ << endl;
        return m_description == nullptr;
    }

    Status::operator int() const {
        //   cout << __FUNCTION__ << endl;
        return m_code;
    }

    Status::operator const char*() const
    {
        return m_description;
    }


    ostream &operator<<(ostream &os,const Status &s)
    {
        if((int)s!=0){
            //cout <<"ERR#" <<m_code <<": ";
            os << "ERR#" <<(int)s <<": ";
        }

        os << (const char *)s;
        return os;
    }

}
