#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
using namespace std;

int main() {
    string str1, str2;
    //»ñÈ¡×Ö·û´®
    getline(cin, str1);
    getline(cin, str2);
    if (str1.size() > str2.size())
    {
        str1.swap(str2);
    }

    char ch;
    size_t Len = 0, MaxLen = 0, i = 0, cp = 0, pos = 0;
    while (cp < str1.size())
    {
        ch = str1[cp];
        pos = str2.find(ch, pos);

        //Æ¥Åä×Ö·û´®
        while ((cp + i) < str1.size() && (pos + i) < str2.size() && str1[cp + i] == str2[pos + i])
        {
            i++;
        }
        Len = i;
        i = 0;
        if (Len > MaxLen)
        {
            MaxLen = Len;
        }
        pos = str2.find(ch, pos + 1);
        if (pos != string::npos)
        {
            continue;
        }
        cp++;
    }
    cout << MaxLen;
    return 0;
}