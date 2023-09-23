#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
using namespace std;

int main() {
    string str1;
    getline(cin, str1);
    string str2;
    size_t i = 0;
    for (i = str1.find_last_of(' ');i != string::npos;i = str1.find_last_of(' '))
    {
        str2.append(str1.begin() + i + 1, str1.end());
        str1.erase(i);
        str2 += ' ';
    }
    str2.append(str1.begin(), str1.end());
    cout << str2;
}