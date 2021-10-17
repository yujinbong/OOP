
/*===============================================
Workshop #4 (Part-2):
==================================================
Name   : Yujin Bong
ID     : 147525208
Email  : ybong@myseneca.ca
        Section: NCC
*/
#ifndef OOPWORKSHOP_CHAPTER_H
#define OOPWORKSHOP_CHAPTER_H
#include <cstring>


namespace sdds{
    const int PAGE = 200;//the pages of the chapters cannot be more than 200.

    class Chapter{
    private:
        char m_cname[51];//The name can be a maximum of 50 characters long
        int m_cpages;

    public:
        Chapter();//Default
        Chapter(const char* name,int pages);
        void setEmpty();
        void setChapter(const char* name);
        void setpage(const int page);
        bool isEmpty()const;
        const char *getChapter() const;
        int getpage()const;
        void display()const;
    };


}

#endif //OOPWORKSHOP_CHAPTER_H
