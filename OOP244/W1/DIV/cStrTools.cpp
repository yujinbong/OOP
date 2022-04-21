#include <iostream>
using namespace std;

void convertToLowerCase(string& str) {
        for (char& ch: str)
                ch = tolower(ch);
}

int F[1000];

void PrefixTable(string& p) {
        int i = 1, j = 0;
        while (i < p.size()) {
                if (p[i] == p[j]) {
                        F[i] = j + 1;
                        i++;
                        j++;
                }
                else if (j > 0)
                        j = F[j - 1];
                else {
                        F[i] = 0;
                        i++;
                }
        }
}

bool checkIfPresent(string str, string subStr) {
        convertToLowerCase(str);
        convertToLowerCase(subStr);

        int i = 0, j = 0;
        PrefixTable(subStr);
        while (i < str.size()) {
                if (str[i] == subStr[j]) {
                        if (j == subStr.size() - 1)
                                return true;
                        i++;
                        j++;
                }
                else if (j > 0)
                        j = F[j - 1];
                else
                        i++;
        }
        return false;
}
