
/*===============================================
Workshop #4 (Part-2):
==================================================
Name   : Yujin Bong
ID     : 147525208
Email  : ybong@myseneca.ca
        Section: NCC
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Book.h"
#include "Chapter.h"
using namespace std;


namespace sdds {
    Book::Book() {
        setEmpty();
    }


    Book::Book(const char* name, int noofchapters, const Chapter* chapters) {
        setEmpty();

        if (name == nullptr || noofchapters == 0)
            return ;


        for (int i = 0; i < noofchapters; i++)
        {
            if(chapters[i].getChapter()==nullptr || strlen(chapters[i].getChapter())==0)
                return ;
            if(chapters[i].getpage()==0 || chapters[i].getpage()>200)
                return ;
        }

        m_bname = new char[strlen(name) + 1];
        strcpy(m_bname, name);
        m_noOfchapters = noofchapters;
        m_chapter = new Chapter[noofchapters];
        for (int i = 0; i < noofchapters; i++)
            m_chapter[i]=chapters[i];
        addchapters=noofchapters;

    }

    void Book::setName(const char* name) {
        delete[] m_bname;
        if (name != nullptr && strlen(name) > 0 ) {
            m_bname = new char[strlen(name) + 1];
            strcpy(m_bname, name);
        }
        else {
            delete[] m_chapter;
            setEmpty();
        }
    }

    Book& Book::addChapter(const char* chapter_name, int noOfPages) {
        if (chapter_name[0]!='\0' && noOfPages > 0 && noOfPages <= PAGE) { // noOfPages > 0
            if(addchapters+1>=m_noOfchapters)
            {
                Chapter *new_chapter = new Chapter[m_noOfchapters+1];
                for (int i = 0; i < m_noOfchapters; i++)
                    new_chapter[i]=m_chapter[i];
                delete [] m_chapter;
                m_chapter=new_chapter;
                m_noOfchapters++;


            }

            m_chapter[addchapters].setChapter(chapter_name);
            m_chapter[addchapters].setpage(noOfPages);
            addchapters++;
        }
        return *this;
    }
    bool Book::isEmpty()const {
        return (m_bname == nullptr || m_bname[0] == '\0');

    }
    void Book::setEmpty() {
        m_bname = nullptr;
        m_noOfchapters = 0;
        m_chapter = nullptr;
    }
    void Book::display()const {
        if (!isEmpty()) {
            cout << "Book Name: " << m_bname << endl;
            cout << "No of Chapters: " << m_noOfchapters << endl;
            cout.width(51);
            cout.fill(' ');
            cout.setf(ios::left);
            cout << "Chapter name";
            cout << "Pages" << endl;
            for (int i = 0; i < m_noOfchapters; i++)
            {
                m_chapter[i].display();
//                if(i>10)
//                {
//                    cout << "... any many more lines will be printed"<< endl;
//                    break;
//                }
            }
        }
        else {
            cout << "Invalid Book object" << endl;
        }

    }
    Book::~Book() {
        delete[] m_chapter;
        delete[] m_bname;
    }



}