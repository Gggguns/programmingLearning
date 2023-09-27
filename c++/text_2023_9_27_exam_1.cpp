#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string str1, str2, str3, str4;
    getline(cin, str1);
    getline(cin, str2);
    int i = 0;
    int count = 0;
    for (i = 0;i <= str1.size();i++)
    {
        str3 = str1;
        str3.insert(str3.begin() + i, str2.begin(), str2.end());
        str4 = str3;
        reverse(str4.begin(), str4.end());
        if (str3 == str4)
        {
            count++;
        }
    }
    cout << count;
    return 0;
}