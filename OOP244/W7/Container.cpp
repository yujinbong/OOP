

#include "Container.h"

using namespace sdds;


void Container::setEmpty() {
    //cout << __FUNCTION__ <<endl;
    validContainer = false;
}

int Container::capacity() {
    //cout << __FUNCTION__ <<endl;
    return Capacity;
}

int Container::volume() {
    //cout << __FUNCTION__ <<endl;
    return Content_volume;
}

Container::Container(const char *Content, int Capacity, int Content_volume) {
    //  cout << __FUNCTION__ <<endl;
    if (Content == NULL || Content_volume > Capacity) {
        validContainer = false;
    } else {
        strcpy(this->Content, Content);
        this->Capacity = Capacity;
        this->Content_volume = Content_volume;
        validContainer = true;
    }
}


int Container::operator+=(int value) {
    // cout << __FUNCTION__ <<endl;
    if (Content_volume + value <= Capacity) {
        Content_volume += value;
    } else {
        value = Capacity - Content_volume;
        Content_volume = Capacity;
    }

    return value;
}

int Container::operator-=(int value) {
    //  cout << __FUNCTION__ <<endl;
    if (Content_volume - value >= 0) {
        Content_volume -= value;
    } else {
        value = Content_volume;
        Content_volume = 0;
    }
    return value;
}


//Returns true if the Container is in a valid state or false if it is not.
bool Container::valid() {
    //   cout << __FUNCTION__ <<endl;
    return validContainer;
}

void Container::clear(int Capacity, const char *Content) {
    //cout << __FUNCTION__ <<endl;
    if (Capacity >= 1 && Content != NULL && strlen(Content) >= 1) {
        this->Capacity = Capacity;
        strcpy(this->Content, Content);
        this->Content_volume = 0;
        validContainer = true;
    }
}

ostream &Container::print(ostream &ost) {
    // cout << __FUNCTION__ <<endl;
    if (validContainer) {
        ost << Content << ": (" << Content_volume << "cc/" << Capacity << ")";
    } else {
        ost << "****: (**cc/***)";
    }
    return ost;
}


istream &Container::read(istream &is) {
    //  cout << __FUNCTION__ <<endl;

    int value;
    if (!validContainer) {
        cout << "Broken Container, adding aborted! Press <ENTER> to continue...." << endl;
        //  is.ignore();

    } else {
        bool validValue = false;
        cout << "Add to ";
        print(cout);

        while (!validValue) {
            cout << endl << "> ";
            is >> value;
            if (value > Capacity) {
                cout << "Invalid Integer, retry:";
            } else if (value < 1 || value > 999) {
                cout << "Value out of range [1<=val<=999]:";

            } else validValue = true;
        }


        value = (*this += value);
        cout << "Added " << value << " CCs" << endl;
    }

    return is;
}
