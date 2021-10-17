
/*===============================================
Workshop #4 (Part-2):
==================================================
Name   : Yujin Bong
ID     : 147525208
Email  : ybong@myseneca.ca
        Section: NCC
*/

#ifndef OOPWORKSHOP_BOOK_H
#define OOPWORKSHOP_BOOK_H
#include "Chapter.h"
#include <cstring>


namespace sdds{

    class Book{
    private:
        char* m_bname;
        int m_noOfchapters;
        Chapter* m_chapter=nullptr;
        int addchapters=0;

    public:
        Book();
        Book(const char* name, int pages,const Chapter* chapters);
        void setName(const char* name);
        Book& addChapter(const char* chapter_name, int noOfPages);
        //  Book& migrate(int chapter);
        bool isEmpty()const;
        void setEmpty();
        ~Book();
        void display()const;


    };




}
#endif //OOPWORKSHOP_BOOK_H