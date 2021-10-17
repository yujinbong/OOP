
/*===============================================
Workshop #5 (Part-1):
==================================================
Name   : Yujin Bong
ID     : 147525208
Email  : ybong@myseneca.ca
        Section: NCC
*/
#include <iostream>

#include "EggCarton.h"
using namespace std;
namespace sdds
{

    void EggCarton::setBroken()
    {
        // size는 6의 계수이며 6-36사이여야하고 계란의갯수는 0에서 상자크기사이여야한다.
        //if ((6 <= m_size && m_size <= 36) && (0 <= m_noOfEggs && m_noOfEggs <= m_size))

        if ( (m_size % 6)!=0 || m_size < 6 || m_size > 36 || 0 > m_noOfEggs || m_noOfEggs > m_size)
            m_noOfEggs = m_size = -1;
    }

    EggCarton::EggCarton(int size, int noOfEggs, bool jumboSize)
    {
        m_size = size;
        m_noOfEggs = noOfEggs;
        m_jumbo = jumboSize; 
        setBroken();
    }

    /*
 The Carton is displayed only if it is not broken (see operator bool() overload),
     otherwise the message: "Broken Egg Carton!"<<endl is displayed.
 */
    ostream &EggCarton::display(std::ostream &ostr) const
    {
        if (operator bool())
        {
            int cartonWidth = m_size == 6 ? 3 : 6; //(조건)? A : B; -> 조건이 맞으면 A, 아니면 B
            for (int i = 0; i < m_size; i++)
            {
                ostr << ((i < m_noOfEggs) ? (m_jumbo ? 'O' : 'o') : '~');
                if ((i + 1) % cartonWidth == 0)
                    cout << endl;
            }
        }
        else
        {
            ostr << "Broken Egg Carton!" << endl;
        }
        return ostr; // In the end, the ostr reference is returned.
    }

    std::istream &EggCarton::read(std::istream &str)
    {
        //문자열과 size,noofeggs 읽어들이기
        char eggtype = ' ';
        str >> eggtype;
        str.ignore(1,','); //,ignore
        str >> m_size;
        str.ignore(1,','); //,ignore
        str >> m_noOfEggs;
/*
        cout << eggtype;
        cout << " ";
        cout << m_size;
        cout << " ";
        cout << m_noOfEggs;
*/
        m_jumbo = (eggtype == 'j'); //check하기

        setBroken();
        //EggCarton; // perform the same validation???

        return str;
    }
    EggCarton::operator bool() const
    {
        return m_size > 0; //상자(size)크기가 0보다 크면 true,상자크기가 깨지지않으면 true.
    }
    EggCarton::operator int() const
    {
        //이 상수 변환은 Carton이 깨지지 않은 경우 계란 수를 반환합니다(bool conversion 사용). 그렇지 않으면 -1이 반환됩니다.
        if (operator bool())
        {
            return m_noOfEggs;
        }
        else
        {
            return -1;
        }
    }
    EggCarton::operator double() const
    {
        // This constant conversion returns the total weight of the eggs
        //  using the constant weight values defined in the header file in Kilos.
        //  (noOfEggs x WeightOfOnEgg)/1000.0 , If the Carton is broken this conversion returns -1.0

        if(! operator bool())
        {
            return -1.0;
        }

        if (m_jumbo)
        {
            return (double)m_noOfEggs *(double)JumboEggWeight / 1000.0;
        }
        else
        {
            return (double)m_noOfEggs *(double)RegularEggWeight/ 1000.0;
        }

    }

    EggCarton &EggCarton::operator--()
    {
        m_noOfEggs--;
        setBroken();
        return *this;
    }

    EggCarton &EggCarton::operator++()
    {
        m_noOfEggs++;
        setBroken();
        return *this;
    }

//a=1;
//b=++a;   //b=2 a=2
//a=1;
//b=a++;   //b=1 a=2
    EggCarton EggCarton::operator--(int)
    {
        // Creates a local copy of the current EggCarton object (*this),
        // calls the prefix operator-- and returns the local copy by value.
        EggCarton before = *this;
        operator--();
        setBroken();
        return before;
    }
    EggCarton EggCarton::operator++(int)
    {
        EggCarton before = *this;
        operator++();
        setBroken();
        return before;
    }

// set
    EggCarton &EggCarton::operator=(int value)
    {
        m_noOfEggs = value;
        setBroken();
        return *this;
    }

// add
    EggCarton &EggCarton::operator+=(int value){
        m_noOfEggs += value;
        setBroken();
        return *this;
    }

// move 3 2  -> 5 0
    EggCarton &EggCarton::operator+=(EggCarton &right)
    {
        int total=m_noOfEggs+int(right);
        if(m_size<total)
        {
            int diff=m_size-m_noOfEggs;
            m_noOfEggs = m_size;
            right+=-diff;
        }
        else
        {
            m_noOfEggs = total;
            right=0;
        }

        setBroken();
        return *this;
    }

    bool EggCarton::operator==(const EggCarton& right) const
    {
        //-0.001 <= value <= 0.001!!!!!!
        // value<= 0.001
        // value=-1.0
        double value=double(right)-operator double();
        if(value<0)
            value=-value;

        return value<=0.001;
    }

    int operator+(int left, const EggCarton &right)
    {
        return left+int(right);
    }

//cout << eggs[0] << "----------" << endl;
    ostream &operator<<(ostream &ostr, const EggCarton &right)
    {
        return right.display(ostr);
    }

// cin >> egg;
    istream &operator>>(istream &istr, EggCarton &right)
    {
        return right.read(istr);
    }


    //현재 카톤의 무게와 오른쪽 카톤의 무게의 차이가 -0.001kg에서 0.001kg 사이이면 참을 반환하고 그렇지 않으면 거짓을 반환합니다.
}

