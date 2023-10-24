#define _CRT_SECURE_NO_WARNINGS
#include <cstddef>
#include <iostream>
#include<string>
using namespace std;

int main() {
    string str1;
    string str2;
    getline(cin, str1);
    getline(cin, str2);
    if (str1.size() > str2.size())
    {
        str1.swap(str2);
    }
    size_t cp = 0;
    size_t i = 0, pos = 0;
    size_t MaxLen = 0;
    size_t Len = 0;
    string ret;
    while (cp < str1.size())
    {
        char ch = str1[cp];
        pos = str2.find(ch, pos);
        //Æ¥Åä×Ö·û´®
        while ((cp + i) < str1.size() && (pos + i) < str2.size() && str1[cp + i] == str2[pos + i])
        {
            i++;
        }
        Len = i;
        i = 0;
        //ÕÒ×î´ó
        if (Len > MaxLen)
        {
            MaxLen = Len;
            ret.assign(str1.begin() + cp, str1.begin() + cp + Len);
        }
        pos = str2.find(ch, pos + 1);
        if (pos != string::npos)
        {
            continue;
        }
        cp++;
    }
    cout << ret;
    return 0;
}