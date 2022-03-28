

#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
#include <cstring>

using namespace std;

namespace sdds {
    class Container {
    private:
        char Content[50 + 1];
        int Capacity;
        int Content_volume;
        bool validContainer;

        //Protected modifier and queries: (only accessible by derived classes)
    protected:
        void setEmpty(); 
        int capacity();

        int volume();

    public:
        Container(const char *Content, int Capacity, int Content_volume = 0);

        int operator+=(int value);

        int operator-=(int value);

        //Returns true if the Container is in a valid state or false if it is not.
        bool valid();

        void clear(int Capacity, const char *Content);

        ostream &print(ostream &out);

        istream &read(istream &in);

        friend ostream &operator<<(ostream &out, Container &C) {
            return C.print(out);
        }

        friend istream &operator>>(istream &in, Container &C) {
            return C.read(in);
        }
    };

}

#endif
