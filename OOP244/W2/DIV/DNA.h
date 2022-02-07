#ifndef W2P2_DNA_H
#define W2P2_DNA_H

#include <iostream>
namespace sdds
{
    struct DNA {
        int d_id;
        char* d_char;
    };

    bool beginSearch(const char* filename);
    bool read(const char* subDNA);
    void sort();
    void displayMatches();
    void deallocate();
    void endSearch();

}
#endif //W2P2_DNA_H
