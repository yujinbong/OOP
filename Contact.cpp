/*===============================================
Workshop #6 (Part-1):
==================================================
Name   : Yujin Bong
ID     : 147525208
Email  : ybong@myseneca.ca
        Section: NCC
*/
#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Contact.h"

using namespace std;
namespace sdds {
    //setstate();
    //peek();

    Contact:: Contact(const char *name, int area, int exchange, int number)
    {
        set(name,area,exchange,number);
    }

    bool Contact::validPhone(int area, int exchange, int number) const {
        return area >= 100 && area<= 999 && exchange >= 100 && exchange <= 999 && number >= 0 &&
               number <= 9999;
    }

    void Contact::setEmpty() {
        delete [] m_name;
        m_name = nullptr; // m_name만?
        m_exchangeCode = 0;
        m_number = 0;
        m_area = 0;
    }

////////////////////////
    void Contact::allocateAndCopy(const char *name) {
        delete[] m_name;
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
    }

    void Contact::extractChar(std::istream &istr, char ch) const {
        //setEmpty() 호출?
        char chinput;
        chinput = istr.peek(); //먼저 키보드 버퍼의 다음 문자가 ch 인수와 동일한지 여부를 확인한후 같으면 읽고 제거한다
        if (chinput == ch) {  //이거 말되는지 확인
            ch = istr.get();
            //istr.get(); //removes dssk? istr.ignore()
        } else {
            istr.setstate(ios::failbit);
        }
    }

    std::ostream &Contact::printPhoneNumber(std::ostream &ostr) const {
        //(999) 999-0009
        /*if (istr.peek() == '-'){
         * istr.get();} */

        ostr << "(";
        ostr << m_area;
        ostr << ") ";
        ostr << m_exchangeCode;
        ostr << "-";
        ostr.width(4);//참고: 마지막 부분(숫자)은 오른쪽 맞춤이며 너비가 4인 0으로 채워집니다.
        ostr.fill('0');
        ostr.setf(ios::left);
        ostr.unsetf(ios::left);
        ostr << m_number;

        return ostr;

    }

    void Contact::set(const char *name, int area, int exchange, int number) {
        if (name != nullptr && name[0] && validPhone(area, exchange, number)) { //void setEmpty함수를 사용할 방법찾아보기
            allocateAndCopy(name);
            m_area = area;
            m_exchangeCode = exchange;
            m_number = number;
        } else {
            setEmpty();
        }
    }

    Contact::Contact() {
        setEmpty();
    }

    Contact::Contact(const Contact &cnt) {
        //cnt 개체가 유효하면 현재 개체의 값이 수신 인수(cnt)의 값으로 설정됩니다.
        if (cnt) {
            set(cnt.m_name,cnt.m_area,cnt.m_exchangeCode,cnt.m_number);
        } else {
            setEmpty();
        }
    }

    Contact &Contact::operator=(const Contact &cnt) {
        if (this != &cnt) {
            set(cnt.m_name,cnt.m_area,cnt.m_exchangeCode,cnt.m_number);
        }
        return *this;
    }

    Contact::~Contact() {
        delete[] m_name;
    }
//             {"Fred Soley", 416,491,50}, 는 합법이아야함
    Contact::operator bool() const {
        return m_name != nullptr && m_name[0] && validPhone(m_area, m_exchangeCode, m_number);
    }

    std::ostream &Contact::print(std::ostream &ostr, bool toFile = true) const {
        /*if (toFile) {
            ostr << m_name;
            ostr << ",";
            printPhoneNumber(ostr);//이거 맞는지 확인하기
        } else {
            */
        if(operator bool())
        {
            if (toFile)
            {
/////////////여기는 파일 처럼 만들기
                ostr.width(50);
                ostr.fill('.');
                ostr.setf(ios::left);
                ostr << m_name;
                printPhoneNumber(ostr);
                ostr.unsetf(ios::left);
            }else
            {
                ostr.width(50);
                ostr.fill('.');
                ostr.setf(ios::left);
                ostr << m_name;
                printPhoneNumber(ostr);
                ostr.unsetf(ios::left);
            }
        }else

            ostr << "Invalid Phone Record";
        return ostr;
    }

    std::istream &Contact::read(std::istream &istr) {
        //Luke Skywalker,(647) 555-9475
        char name[MaxNameLength];
        int area;
        int exchange;
        int number;


        istr.get(name, MaxNameLength, ',');//55자 이상 금지!!!
        extractChar(istr, ',');//쉼표 추출
        if(istr.fail())
        {
            return istr;
        }
        extractChar(istr, '(');// ( 추출
        if(istr.fail())
        {
            return istr;
        }
        istr >> area;

        extractChar(istr, ')');//) 추출
        if(istr.fail())
        {
            return istr;
        }
        extractChar(istr, ' ');//스페이스바추출
        istr >> exchange;
        if(istr.fail())
        {
            return istr;
        }
        extractChar(istr, '-');//- 추출
        istr >> number;

        if(istr.fail())
        {
            return istr;
        }
        extractChar(istr, '\n'); //\n라인 추출
        if(istr.fail())
        {
            return istr;
        }
        set(name, area, exchange, number);

        return istr;
    }


    std::ostream &operator<<(std::ostream &ostr, const Contact &cnt) {
        return cnt.print(ostr,false);

    }

    std::istream &operator>>(std::istream &istr, Contact &cnt) {
        return cnt.read(istr);
    }


}














