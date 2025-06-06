#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string str1;
        string str2;
        int size = s.size();
        for (int i = 0; i < size; i++)
        {
            char ch = s[i];
            if (ch == '#')
            {
                if (str1.size())str1.pop_back();
            }
            else str1 += ch;
        }
        size = t.size();
        for (int i = 0; i < size; i++)
        {
            char ch = t[i];
            if (ch == '#')
            {
                if (str2.size())str2.pop_back();
            }
            else str2 += ch;
        }
        return str1 == str2;
    }
};
int main()
{
    return 0;
}