#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "HealthCard.h"
using namespace std;
namespace sdds {

    bool HealthCard::validID(const char *name, long long number, const char vCode[], const char sNumber[]) const {
        return name != nullptr && strlen(name) > 0 && number >999999999 && number < 9999999999 && strlen(vCode) == 2 && strlen(sNumber) == 9;
    }

    void HealthCard::setEmpty() {
        m_name = nullptr;
    }

    void HealthCard::allocateAndCopy(const char *name) {
        delete[] m_name;
        m_name=nullptr;
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
    }

    void HealthCard::extractChar(istream &istr, char ch) const {
        //  cout << __FUNCTION__ << endl;
        if(istr.peek() != ch){

            istr.setstate(ios::failbit);}
        else{
            istr.ignore();}
    }

    ostream &HealthCard::printIDInfo(ostream &ostr) const {
        //  cout << __FUNCTION__ << endl;
        ostr << m_number <<"-" << m_vCode <<", "<<m_sNumber;
        return ostr;//and then returns the istr object reference??
    }

    void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[]){
        if(validID(name,number,vCode,sNumber)){
            allocateAndCopy(name);
            m_number=number;
            strcpy(m_vCode,vCode);
            strcpy(m_sNumber,sNumber);
        }
        else{
            delete[] m_name;
            setEmpty();
        }
    }



    HealthCard::HealthCard(const char* name,long long number, const char vCode[], const char sNumber[]){
        set(name,number,vCode,sNumber);
    }
    HealthCard::HealthCard(const HealthCard& hc){
        if(*this)
            set(hc.m_name,hc.m_number,hc.m_vCode,hc.m_sNumber);
    }


    HealthCard& HealthCard:: operator=(const HealthCard& hc){
        if(this != &hc){
            set(hc.m_name,hc.m_number,hc.m_vCode,hc.m_sNumber);
        }
        return *this;
    }

    HealthCard::~HealthCard(){
        delete[] m_name;
    }
    HealthCard::operator bool() const{
        return m_name != nullptr;
    }

    ostream& HealthCard:: print(ostream& ostr, bool toFile) const{
        if(*this) {
            if(toFile){
                ostr << m_name<<",";
                printIDInfo(ostr) << endl;
            }
            else{
                cout.fill('.');
                cout << left;
                cout.width(50);
                cout << m_name;
                printIDInfo(ostr);
            }
        }
        return ostr;
    }
    istream& HealthCard::read(istream& istr){
        char name[MaxNameLength];
        long long num=-1;
        char vCode[3],sNumber[10];

        istr.get(name,MaxNameLength,',');
        extractChar(istr,',');
        istr >>num;
        extractChar(istr, '-');
        istr.get(vCode,3,',');
        extractChar(istr,',');
        istr.get(sNumber,10);


        if(!istr.fail()){
            set(name,num,vCode,sNumber);
        }
        istr.clear();

        istr.ignore(1000,'\n');//enter2번쳐야함..
        return istr;
    }
    ostream& operator<<(ostream& ostr, const HealthCard& hc) {
        if (hc) {
            hc.print(ostr, false);
        }else{
            ostr<<"Invalid Health Card Record";}
        return ostr;
    }
    istream& operator>>(istream& istr, HealthCard& hc){
        return hc.read(istr);
    }











}
