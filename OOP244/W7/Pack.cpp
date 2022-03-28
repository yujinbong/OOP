#include "Pack.h"

using namespace sdds;


Pack::Pack(const char *Content, int Size, int unitSize, int NumberOfUnits)
        : Container(Content, Size * unitSize, unitSize * NumberOfUnits) {
    //  cout << __FUNCTION__ <<endl;
    this->size = Size;
    this->unitSize = unitSize;
    this->numberOfUnits = NumberOfUnits;
}


int Pack::operator+=(int units) {
    //   cout << __FUNCTION__ <<endl;
    int result = Container::operator+=(units * unitSize) / unitSize;
    this->numberOfUnits += result;
    return result;
}


int Pack::operator-=(int units) {
//cout << __FUNCTION__ <<endl;
    int result = Container::operator-=(units * unitSize) / unitSize;
    this->numberOfUnits -= result;
    return result;
}


// returns the unit size attribute
int Pack::unit() {
    //   cout << __FUNCTION__ <<endl;
    return unitSize;
}


// returns the content volume of the Base class divided by the unit size
int Pack::noOfUnits() {
    //  cout << __FUNCTION__ <<endl;
    return numberOfUnits;
}


// return the capacity of the base class divided by the unit size
int Pack::Size() {
    return size;
}


void Pack::clear(int packSize, int unitSize, const char *content) {
//    cout << __FUNCTION__ <<endl;
    if (unitSize > 0) {
        Container::clear(packSize * unitSize, content);
        this->size = packSize;
        this->unitSize = unitSize;
        this->numberOfUnits = 0;

    }
}


ostream &Pack::print(ostream &out) {
    //  cout << __FUNCTION__ <<endl;
    Container::print(out);
    if (valid()) {
        out << ", " << numberOfUnits << " in a pack of " << size;
    }

    return out;
}


istream &Pack::read(istream &in) {
    //cout << __FUNCTION__ <<endl;

    int units;

    if (!valid()) {
        cout << "Broken Container, adding aborted! Press <ENTER> to continue...." << endl;
    } else if (numberOfUnits == size) {

        cout << "Pack is full!, press <ENTER> to continue..." << endl;
        //ch = getchar();
    } else {
        bool validValue = false;
        cout << "Add to ";
        print(cout);

        int maxVal = size - numberOfUnits;

        while (!validValue) {
            cout << endl << "> ";
            in >> units;
            if (units > size) {
                cout << "Invalid Integer, retry: ";
            } else if (units < 1 || units > maxVal) {
                cout << "Value out of range [1<=val<=" << maxVal << "]: " << maxVal << endl;
                validValue = true;
            } else validValue = true;
        }

        units = (*this += units);
        cout << "Added " << units << endl;
    }

    return in;
}
