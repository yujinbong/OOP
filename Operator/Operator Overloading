#include <iostream>

class number {
private:
    int m_value;

public:
    number(int value = 0);

    number operator+(const number &p);
    number &operator+=(const number &p);
    number &operator++();
    number operator++(int);
    number &operator--();

    std::ostream &print(std::ostream &ostr = std::cout) const;
};


std::ostream &operator<<(std::ostream &ostr, const number &N)
{
    return N.print(ostr);    
}

/// Your task:
/// Overload the += operator , + Operator and ++ post and prefix operator so the following
/// operatoins work properly:
using namespace std;

number::number(int value)
{
    m_value=value;
}

void prn(const number &a, const number &b, const number &c) {
    cout << "c  a  b " << endl
         << c << " " << a << " " << b << endl;
    cout << "--------------------" << endl;
}


number number::operator+(const number &p) {
    return number(m_value + p.m_value);
}

number &number::operator++() {
    m_value++;
    return *this;
}

number number::operator++(int) {
    number temp = *this;
    m_value++;
    return temp;
}

number &number::operator--() {
    m_value--;
    return *this;
}

number &number::operator+=(const number &p) {
    m_value+=p.m_value;
    return *this;
}

std::ostream &number::print(std::ostream &ostr) const
{
    ostr << m_value;
    return ostr;
}

int main() {
    number a{10}, b{20}, c;
    c = a + b;
    prn(a, b, c);
    c = ++a;
    prn(a,b,c);
    c = a += b;
    prn(a,b,c);
    c = b++;
    prn(a, b, c);
    return 0;
}

/// output:
/*
c  a  b
30 10 20
--------------------
c  a  b
11 11 20
--------------------
c  a  b
31 31 20
--------------------
c  a  b
20 31 21
--------------------
 */
