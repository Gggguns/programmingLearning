#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
using namespace std;

int main()
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    //É¾³ı³öÏÖµÄ×Ö·û
    int i = 0;
    for (auto e : str2)
    {
        for (i = str1.find(e);i != string::npos;i = str1.find(e))
        {
            str1.erase(str1.begin() + i);
        }
    }
    cout << str1;
}