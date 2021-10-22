/*===============================================
Workshop #6 (Part-1):
==================================================
Name   : Yujin Bong
ID     : 147525208
Email  : ybong@myseneca.ca
        Section: NCC
*/
#ifndef SDDS_CONTACT_H
#define SDDS_CONTACT_H

#include <iostream>

namespace sdds {
    const int MaxNameLength = 55;//연락처의 이름은 동적으로 유지되지만 이름에 대해 가능한 최대 크기는 상수 값을 통해 55자로 설정됩니다.
    class Contact {
        char *m_name{}; // sets m_name to nullptr before any constructor invocation  name should be not null
        int m_area; //break phone number 3part
        int m_exchangeCode; //break phone number 3part
        int m_number; //break phone number 3part
        void setEmpty(); //m_name을 nullptr로 설정하여 Contact개체를 인식 가능한 빈상태로 설정한다.
        void allocateAndCopy(const char *name);

        bool validPhone(int area, int exchange, int number) const; //return true는 전화번호의 세부분이 유효하는것을 말한디.
        void extractChar(std::istream &istr, char ch) const;

        std::ostream &printPhoneNumber(std::ostream &ostr) const;

        void set(const char *name, int area, int exchange, int number);

    public:
        Contact();
        Contact(const char *name, int area, int exchange, int number);
        Contact(const Contact &cnt);// Copy
        Contact &operator=(const Contact &cnt);// Copy Assingment
        ~Contact();//Destructor
        operator bool() const;//Returns true if m_name is not null, else it will return false;
        std::ostream &print(std::ostream &ostr, bool) const;

        std::istream &read(std::istream &istr);

    };

    std::ostream &operator<<(std::ostream &ostr, const Contact &cnt);

    std::istream &operator>>(std::istream &istr, Contact &cnt);


}
#endif // !SDDS_CONTACT_H
