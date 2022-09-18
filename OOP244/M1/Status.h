/*
Final project Milestone 1
 Filename: Status.h
name: Yujin Bong
student ID :147525208
SECTION : NDD
PROFESSOR : Arezoo.tony
Date: 2022/03/13
Author: Fardad Soleimanloo   2022-02-28
Revision History
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/


#ifndef MS1_STATUS_H
#define MS1_STATUS_H
using namespace std;
namespace sdds {

    class Status {
        int m_code=0;  // 0 m_description=nullptr 정상, 1 high, -1 low
        char *m_description=nullptr; //

        void set(const char *description);

    public:
        //roule of three
        Status(const char *description = nullptr);
        Status(const Status &s);

        Status &operator=(const Status &s);

        ~Status();

        //Assignment operator overloads
        Status &operator=(const char *description);

        Status &operator=(int code);

        //The clear() method
        Status &clear();

        //bool overload
        operator bool() const;
        operator int() const;
        operator const char*() const;
        // Status& operator << (const char*);
        // const char* operator << (const char*);


    };


    //Helper insertion operator overload
    ostream &operator<<(ostream &os,const Status &s);

}

#endif //MS1_STATUS_H
