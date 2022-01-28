/*
    ==================================================
    Workshop #1 (Part-1):
    ==================================================
    Name   : Yujin Bong
    ID     : 147525208
    Email  : ybong@myseneca.ca
    Section: NDD
*/

#ifndef SDDS_CSTRTOOLS_H
#define SDDS_CSTRTOOLS_H




namespace sdds {

    char toLower(char ch);
    int strCmp(const char* s1, const char* s2);
    int strnCmp(const char* s1, const char* s2, int len);
    const char* strStr(const char* str, const char* find);
    void strCpy(char* des, const char* src);
    int strLen(const char* str);
    int isAlpha(char ch);
    int isSpace(char ch);
    void trim(char word[]);
    void toLowerCaseAndCopy(char des[], const char source[]);


}
#endif //SDDS_CSTRTOOLS_H
